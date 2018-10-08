#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int CP=682*999;
int n, m, s, t, i, j, u, v;
int pre[CP], to[CP], head[CP], wcnt;
int q[CP], ql, qr;
int dis[CP];
bool vis[CP];
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add1edge(int u, int v){ addedge(u, v); addedge(v+n, u+n); }
inline void bfs(int s){
    int i, u, v;
    memset(dis, -1, sizeof(dis));
    q[ql=qr=1]=s;
    dis[s]=0;
    while(ql<=qr){
        u=q[ql++];
        for(i=head[u]; i; i=pre[i]) if(!(~dis[v=to[i]]) and !vis[to[i]]){
            dis[v]=dis[u]+1;
            q[++qr]=v;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &u, &v);
        add1edge(u, v);
    }
    scanf("%d %d", &s, &t);
    bfs(t+n);
    for(i=1; i<=n; i++){
        for(j=head[i]; j and ~dis[to[j]+n]; j=pre[j]);
        vis[i]=bool(j);
        // printf("%d %d\n", i, bool(j));
    }
    bfs(s);
    printf("%d\n", dis[t]);
    return 0;
}
