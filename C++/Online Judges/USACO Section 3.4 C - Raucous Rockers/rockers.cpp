/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: rockers
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
int i, j, k, l, o, n, t, m;
int a[25];
int f[25][25][25];
int ans;
// 表示到第i首歌曲用了j张唱片，j张唱片还剩下k分钟可以储存的最多歌曲数目
int main(){
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    memset(f, 0x80, sizeof(f));
    scanf("%d %d %d", &n, &t, &m);
    f[0][0][0]=0;
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    for(i=1; i<=n; i++){
        f[i][0][0]=0;
        for(j=1; j<=m and j<=i; j++){
            for(k=0; k<=t; k++){
                if(k+a[i]<=t) f[i][j][k]=max(f[i][j][k], f[i-1][j][k+a[i]]+1);
                f[i][j][k]=max(f[i][j][k], f[i-1][j][k]);
                if(k==t-a[i]) for(l=0; l<=t; l++) f[i][j][k]=max(f[i][j][k], f[i-1][j-1][l]+1);
            }
        }
    }
    ${
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                for(k=0; k<=t; k++)
                    if(f[i][j][k]>=0) printf("%d ", f[i][j][k]);
                    else printf("- ");
                putchar('\n');
            }
            putchar('\n');
        }
    }
    for(i=0; i<=m; i++) for(j=0; j<=t; j++) ans=max(ans, f[n][i][j]);
    printf("%d\n", ans);
    return 0;
}
