#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ri register int
using namespace std;
const int SCP=682*999/2, INF=0x3f3f3f3f;
int pre[SCP], to[SCP], f[SCP], head[SCP], wcnt=1;
int h[SCP], c[SCP], e[SCP], q[SCP], ql, qr;
int i, n, m, s, t, u, v, w;
struct Nodecmp{ bool operator () (int x, int y) const{ return h[x] < h[y]; } };
priority_queue<int, vector<int>, Nodecmp> pq;
inline void addedge(int u, int v, int w){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; f[wcnt]=w; }
inline void add1edge(int u, int v, int w){ addedge(u, v, w); addedge(v, u, 0); }
inline void bfs(){
    memset(h, 0x3f, sizeof(h));
    ri i, u, v;
    q[ql=qr=1]=t;
    h[t]=0;
    while(ql<=qr){
        u=q[ql++];
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
        if(v^s and v^t and !e[v]) pq.push(v);
        flow=min(e[u], f[i]);
        f[i]-=flow; f[i^1]+=flow; e[u]-=flow; e[v]+=flow;
    }
}
inline void remark(int u){
    ri i;
    h[u]=INF;
    for(i=head[u]; i; i=pre[i]) if(f[i]) h[u]=min(h[u], h[to[i]]+1);
}
inline void gap(int x){
    ri i;
    for(i=1; i<=n; i++) if(x<h[i] and h[i]<=n) h[i]=n+1;
}
inline int hlpp(){
    ri i, u, v;
    bfs();
    for(i=1; i<=n; i++) if(h[i]^INF) c[h[i]]++;
    for(i=head[s]; i; i=pre[i]) if(f[i]){
        v=to[i];
        if(!e[v] and v^s and v^t) pq.push(v);
        e[v]+=f[i]; f[i^1]+=f[i]; f[i]=0;
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
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &w);
        add1edge(u, v, w);
    }
    printf("%d\n", hlpp());
    return 0;
}
