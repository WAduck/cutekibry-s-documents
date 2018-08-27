/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: fence
*/
#include <cstdio>
using namespace std;
int w[505][505];
bool deg[505], vis[505];
int cc[1050], ccn;
int n, m, u, v, i;
void findpath(int u){
    int i;
    for(i=1; i<=n; i++) if(w[u][i]){
        w[u][i]--;
        w[i][u]--;
        findpath(i);
    }
    cc[++ccn]=u;
}
int main(){
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    n=500;
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &u, &v);
        w[u][v]++;
        w[v][u]++;
        vis[u]=vis[v]=1;
        deg[u]=!deg[u];
        deg[v]=!deg[v];
    }
    for(i=1; !deg[i] and i<=n; i++);
    if(i<=n) findpath(i);
    else{
        for(i=1; !vis[i]; i++);
        findpath(i);
    }
    while(ccn) printf("%d\n", cc[ccn--]);
    return 0;
}
