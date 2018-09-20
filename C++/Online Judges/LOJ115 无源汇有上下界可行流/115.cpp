#include <cstdio>
#include <cstring>
#include <queue>
#define ri register int
using namespace std;
const int SCP=682*999/60, INF=0x3f3f3f3f;
int pre[SCP<<2], to[SCP<<2], f[SCP<<2], net[SCP], wcnt=1;
int h[SCP], e[SCP], c[SCP], q[SCP], head[SCP], ql, qr;
int n, m, s, t, sum;
int z[SCP];
struct cmp{ bool operator () (int a, int b){ return h[b] < h[a]; } };
priority_queue<int, vector<int>, cmp> pq;
inline void addedge(int u, int v, int w){
    pre[++wcnt]=head[u];
    head[u]=wcnt;
    to[wcnt]=v;
    f[wcnt]=w;
}
inline void add1edge(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
inline void bfs(){
    memset(h, 0x3f, sizeof(h));
    ri i, u, v;
    q[ql=qr=1]=t;
    h[t]=0;
    while(ql<=qr){
        u=q[ql++];
        c[h[u]]++;
        for(i=head[u]; i; i=pre[i]) if(!f[i] and h[v=to[i]]==INF){
            h[v]=h[u]+1;
            q[++qr]=v;
        }
    }
    h[s]=n;
}
inline void push(int u){
    ri i, v, flow;
    for(i=head[u]; i and e[u]; i=pre[i]) if(f[i] and h[u]-1==h[v=to[i]]){
        if(!e[v] and v^s and v^t) pq.push(v);
        flow=min(e[u], f[i]);
        f[i]-=flow; f[i^1]+=flow; e[u]-=flow; e[v]+=flow;
    }
}
inline void remark(int u){
    h[u]=INF;
    for(ri i=head[u]; i; i=pre[i]) if(f[i]) h[u]=min(h[u], h[to[i]]+1);
}
inline void gap(int x){
    for(ri i=1; i<=n; i++) if(x<h[i] and h[i]<=n) h[i]=n+1;
}
inline int hlpp(){
    ri i, u, v, cnt=0;
    bfs();
    for(i=head[s]; i; i=pre[i]) if(f[i] and h[v=to[i]]^INF){
        if(!e[v] and v^s and v^t) pq.push(v);
        f[i^1]+=f[i]; e[v]+=f[i]; f[i]=0;
    }
    while(!pq.empty()){
        u=pq.top();
        pq.pop();
        push(u);
        if(e[u]){
            if(!--c[h[u]]) gap(h[u]);
            remark(u);
            c[h[u]]++;
            pq.push(u);
        }
    }
    return e[t];
}
int main(){
    ri i, u, v, lb, ub;
    scanf("%d %d", &n, &m);
    s=n+1;
    t=n+2;
    n+=2;
    for(i=1; i<=m; i++){
        scanf("%d %d %d %d", &u, &v, &lb, &ub);
        add1edge(u, v, ub-lb);
        net[v]+=lb;
        net[u]-=lb;
        z[i]=lb;
    }
    for(i=1; i<=n-2; i++){
        if(net[i]>0) add1edge(s, i, net[i]), sum+=net[i];
        else add1edge(i, t, -net[i]);
    }
    if(sum^hlpp()) printf("NO");
    else{
        printf("YES\n");
        for(i=1; i<=m; i++) printf("%d\n", f[(i<<1)|1]+z[i]);
    }
    return 0;
}
