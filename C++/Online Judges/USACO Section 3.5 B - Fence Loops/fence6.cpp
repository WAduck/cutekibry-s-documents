/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: fence6
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const int INF=0x3f3f3f3f;
int seg[105][2];
int w[505][505], dis[505][505];
int no[105], len[105], n1[2][105];
int a[105][2][10];
int i, j, k, k1, k2, n, m, u, v, x;
int ans;
int main(){
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    memset(w, 0x3f, sizeof(w));
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d", &x);
        scanf("%d %d %d", &len[x], &n1[0][x], &n1[1][x]);
        for(j=1; j<=n1[0][x]; j++) scanf("%d", &a[x][0][j]);
        for(j=1; j<=n1[1][x]; j++) scanf("%d", &a[x][1][j]);
    }
    for(u=1; u<=m; u++){
        for(k1=0; k1^2; k1++){
            for(i=1; i<=n1[k1][u]; i++){
                v=a[u][k1][i];
                for(k2=0; k2^2; k2++){
                    for(j=1; j<=n1[k2][v] and a[v][k2][j]^u; j++);
                    if(j<=n1[k2][v] and seg[v][k2])
                        seg[u][k1]=seg[v][k2];
                }
            }
            if(!seg[u][k1]) seg[u][k1]=++n;
        }
        w[seg[u][0]][seg[u][1]]=w[seg[u][1]][seg[u][0]]=len[u];
    }
    $ for(i=1; i<=m; i++) printf("# %d %d %d\n", i, seg[i][0], seg[i][1]);
    ans=INF;
    memcpy(dis, w, sizeof(w));
    for(k=1; k<=n; k++){
        for(i=1; i<k; i++)
            for(j=i+1; j<k; j++) if(w[i][k]<INF and w[k][j]<INF)
                ans=min(ans, dis[i][j]+w[i][k]+w[k][j]);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    }
    printf("%d\n", ans);
    return 0;
}
