/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: ditch
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const int INF=0x3f3f3f3f;
int pre[405], to[405], f[405], head[205], dep[205], cnt=1;
int q[405];
int s, t, n, m;
inline void addedge(int u, int v, int w){
    pre[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    f[cnt]=w;
}
inline void add2edge(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
inline bool bfs(){
    int ql, qr, i, u, v;
    memset(dep, 0, sizeof(dep));
    q[ql=qr=1]=s;
    dep[1]=1;
    while(ql<=qr){
        u=q[ql++];
        for(i=head[u]; i; i=pre[i]) if(!dep[v=to[i]] and f[i]){
            dep[v]=dep[u]+1;
            q[++qr]=v;
        }
    }
    ${
        for(i=1; i<=n; i++) printf("%d ", dep[i]);
        putchar('\n');
    }
    return dep[t];
}
int flow(int u, int lim){
    int tot=0, i, v, temp;
    if(u==t) return lim;
    for(i=head[u]; i and lim-tot; i=pre[i]) if(dep[u]+1==dep[v=to[i]] and f[i]){
        temp=flow(v, min(lim-tot, f[i]));
        tot+=temp;
        f[i]-=temp;
        f[i^1]+=temp;
    }
    if(!tot) dep[u]=-1;
    return tot;
}
int main(){
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    int i, j, u, v, w, ans=0, temp;

    scanf("%d %d", &m, &n);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &w);
        add2edge(u, v, w);
    }
    s=1; t=n;
    while(bfs()) ans+=flow(s, INF);
    printf("%d\n", ans);
    return 0;
}
