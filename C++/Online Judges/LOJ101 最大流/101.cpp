#include <cstdio>
#include <cstring>
typedef long long int64;
using namespace std;
const int SCP=682*999/60;
const int64 INF=0x7fffffffffffffff;
int pre[SCP], to[SCP], f[SCP], head[SCP], wcnt=1;
int dep[SCP], q[SCP], ql, qr;
int n, m, s, t, i, u, v, w;
inline int64 min(int64 a, int64 b){ return (a<b)?a:b; }
inline void addedge(int u, int v, int w){
    pre[++wcnt]=head[u];
    head[u]=wcnt;
    to[wcnt]=v;
    f[wcnt]=w;
}
inline void add1edge(int u, int v, int w){ addedge(u, v, w); addedge(v, u, 0); }
inline bool bfs(){
    int i, u, v;
    memset(dep, 0, sizeof(dep));
    dep[s]=1;
    q[ql=qr=1]=s;
    while(ql<=qr){
        u=q[ql++];
        for(i=head[u]; i; i=pre[i]) if(f[i] and !dep[v=to[i]]){
            dep[v]=dep[u]+1;
            q[++qr]=v;
        }
    }
    return dep[t];
}
int64 maxflow(int u, int64 lim){
    int64 tot=0, flow;
    int i, v;
    if(u==t) return lim;
    for(i=head[u]; i and lim-tot; i=pre[i]) if(dep[u]+1==dep[v=to[i]] and (w=f[i])){
        flow=maxflow(v, min(lim-tot, f[i]));
        f[i]-=flow;
        f[i^1]+=flow;
        tot+=flow;
    }
    if(!tot) dep[u]=-1;
    return tot;
}
int64 dinic(){
    int64 tot=0;
    while(bfs()) tot+=maxflow(s, INF);
    return tot;
}
int main(){
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &w);
        add1edge(u, v, w);
    }
    printf("%lld\n", dinic());
    return 0;
}
