/*
b-a>=3  a---3-->b
c-b>=3  b---3-->c
c-a>=2  a---2-->c
c-a>=6

b-a<=c
a-b>=-c b---(-c)--->a
*/
#include <cstdio>
using namespace std;
const int SCP=682*999/6;
int dis[SCP];
int pre[SCP], to[SCP], wdis[SCP], head[SCP], cnt;
int q[SCP*20], ql, qr; bool vis[SCP];
int n, m, i, u, v, w;
inline void addedge(int u, int v, int w){ pre[++cnt]=head[u]; head[u]=cnt; to[cnt]=v; wdis[cnt]=w; }
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) dis[i]=-1e9, addedge(i-1, i, 0), addedge(i, i-1, -1); //a[i]-a[i-1]>=0 a[i]-a[i-1]<=1
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &w);
        addedge(u-1, v, w); //a[v]-a[u-1]>=w
    }
    q[ql=qr=1]=0;
    while(ql<=qr){
        vis[u=q[ql++]]=0;
        for(i=head[u]; i; i=pre[i]) if(dis[u]+(w=wdis[i])>dis[v=to[i]]){
            dis[v]=dis[u]+w;
            if(!vis[v]){
                q[++qr]=v;
                vis[v]=1;
            }
        }
    }
    printf("%d\n", dis[n]);
    return 0;
}
