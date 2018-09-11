/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: milk6
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 INF=0x3f3f3f3f3f3f3f3f;
const int SCP=682*999/600;
int nxt[SCP<<1], to[SCP<<1], head[35], tail[35], cnt=1; int64 f[SCP<<1]; bool cut[SCP<<1];
int q[35], dep[35], ql, qr;
int sorta[SCP];
int x[SCP], y[SCP]; int64 z[SCP];
int n, m, i, j, s, t;
int64 ans; int ans2; int64 temp;
bool flag;
inline void addedge(int u, int v, int64 w){
    cnt++;
    if(!head[u]) head[u]=tail[u]=cnt;
    else{
        nxt[tail[u]]=cnt;
        tail[u]=cnt;
    }
    to[cnt]=v;
    f[cnt]=w;
}
inline void add2edge(int u, int v, int64 w){ addedge(u, v, w); addedge(v, u, 0); }
inline bool bfs(){
    memset(dep, 0, sizeof(dep));
    int i, j, u, v;
    q[ql=qr=1]=s;
    dep[s]=1;
    while(ql<=qr){
        u=q[ql++];
        for(i=head[u]; i; i=nxt[i]) if(!dep[v=to[i]] and f[i]){
            dep[v]=dep[u]+1;
            q[++qr]=v;
        }
    }
    return dep[t];
}
int64 maxflow(int u, int64 lim){
    int i, v;
    int64 tot=0, flow;
    if(u==t) return lim;
    for(i=head[u]; i and tot-lim; i=nxt[i]) if(dep[u]+1==dep[v=to[i]] and f[i]){
        flow=maxflow(v, min(lim-tot, f[i]));
        f[i]-=flow;
        f[i^1]+=flow;
        tot+=flow;
    }
    if(!tot) dep[u]=-1;
    return tot;
}
int64 dinic(){
    int64 res=0;
    while(bfs()) res+=maxflow(s, INF);
    return res;
}
int main(){
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    scanf("%d %d", &n, &m);
    s=1;
    t=n;
    for(i=1; i<=m; i++){
        scanf("%d %d %lld", &x[i], &y[i], &z[i]);
        add2edge(x[i], y[i], z[i]);
    }
    printf("%lld ", ans=dinic());
    for(i=1; i<=m; i++){
        f[i<<1|1]=0;
        if(!f[i<<1]) z[i]=f[i<<1]=1;
        else z[i]=f[i<<1]=INF;
    }
    printf("%d\n", ans2=dinic());
    for(i=1; i<=m; i++) if(z[i]==1){
        for(j=1; j<=m; j++) f[j<<1]=bool(z[j]), f[j<<1|1]=0;
        f[i<<1]=0;

        if(ans2-1==dinic()) printf("%d\n", i), ans2--, z[i]=0;
    }
    return 0;
}
