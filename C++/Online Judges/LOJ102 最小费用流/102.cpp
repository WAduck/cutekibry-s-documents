#include <cstdio>
using namespace std;
const int SCP=682*999/20, INF=0x7fffffff;
int pre[SCP], from[SCP], to[SCP], f[SCP], c[SCP], wcnt=1;
int dis[SCP], q[SCP<<3], mark[SCP], ql, qr;
bool vis[SCP];
int ans1, ans2;
int n, m, s, t, i, u, v, w, cost;
inline void addedge(int u, int v, int w, int cost){
    pre[++wcnt]=head[u];
    head[u]=wcnt;
    from[wcnt]=u;
    to[wcnt]=v;
    f[wcnt]=w;
    c[wcnt]=cost;
}
inline void add1edge(int u, int v, int w, int cost){ addedge(u, v, w, cost); addedge(v, u, 0, -cost); }
inline bool spfa(){
    int i, u, v, cost;
    for(i=1; i<=n; i++) dis[i]=INF;
    q[ql=qr=1]=s;
    dis[s]=0;
    while(ql<=qr){
        u=q[ql++];
        vis[u]=0;
        for(i=head[u]; i; i=pre[i]) if(f[i] and dis[u]+(cost=c[i])<dis[v=to[i]]){
            dis[v]=dis[u]+cost;
            mark[v]=i;
            if(!vis[v]){
                vis[v]=1;
                q[++qr]=v;
            }
        }
    }
    return dis[t]^INF;
}
inline void mcmf(){
    int flow, i;
    while(spfa()){
        flow=INF;
        for(i=t; mark[i]; i=from[mark[i]]) flow=min(flow, f[mark[i]]);
        for(i=t; mark[i]; i=from[mark[i]]){
            ans2+=c[i]*flow;
            f[i]-=flow;
            f[i^1]+=flow;
        }
        ans1+=flow;
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d %d", &u, &v, &w, &cost);
        add1edge(u, v, w, cost);
    }
    s=1;
    t=n;
    mcmf();
    printf("%d %d\n", ans1, ans2);
    return 0;
}
