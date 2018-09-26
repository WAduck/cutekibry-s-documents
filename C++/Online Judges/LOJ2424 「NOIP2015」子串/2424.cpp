/*
设 f[i][j][k] 表示i个串，匹配到Aj和Bk。
则
f[i][j][k]=f[i-1][0..j-1][k-1]
          +f[i-1][0..j-2][k-2]
          +f[i-1][0..j-3][k-3]
          +...
其中 f[0][j][0]=1。
考虑 sum[i][j][k]=f[i][0..j][k]=f[i][j][k]+sum[i][j-1][k]
则
f[i][j][k]=sum[i-1][j-1][k-1]
          +sum[i-1][j-2][k-2]
          +sum[i-1][j-3][k-3]
即
f[i][j][k]=sum[i-1][j-1][k-1]
          +f[i][j-1][k-1]
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const int MOD=1e9+7;
int f[1005][205], sum[1005][205];
char a[1005], b[205];
int i, j, k;
int n, m, p;
int main(){
    scanf("%d %d %d", &n, &m, &p);
    scanf("%s %s", a+1, b+1);
    for(i=0; i<=n; i++) sum[i][0]=1;
    for(i=1; i<=p; i++){
        for(j=1; j<=n; j++){
            for(k=1; k<=m; k++){
                if(a[j]^b[k]) f[j][k]=0;
                else f[j][k]=(sum[j-1][k-1]+f[j-1][k-1])%MOD;
            }
        }
        for(j=0; j<=n; j++)
            for(k=0; k<=m; k++)
                sum[j][k]=(f[j][k]+(j?sum[j-1][k]:0))%MOD;
        ${
            for(j=1; j<=n; j++){
                for(k=1; k<=m; k++) printf("%d ", f[j][k]);
                putchar('\n');
            }
            putchar('\n');
        }
    }
    printf("%d\n", sum[n][m]);
    return 0;
}
