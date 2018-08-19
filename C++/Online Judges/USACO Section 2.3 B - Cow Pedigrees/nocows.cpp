/*
ID: TsukXmaru Oshawott
LANG: C++
TASK: nocows
*/
#include <cstdio>
using namespace std;
const int MOD=9901;
int f[205][105];
/*
f[i][j]=sum{f[k][j-1]*f[i-k-1][x])
       +sum{f[k][x]*f[i-k-1][j-1]}
       +f[k][j-1]*f[i-k-1][j-1]
*/
int n, m;
int i, j, k, x;
int main(){
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    scanf("%d %d", &n, &m);
    f[1][1]=1;
    for(i=2; i<=n; i++){
        for(j=1; j<=m and j<=i; j++){
            for(k=1; i-k-1; k++){
                f[i][j]=(f[i][j]+f[k][j-1]*f[i-k-1][j-1])%MOD;
                for(x=1; x<j-1; x++)
                    f[i][j]=(f[i][j]+f[k][j-1]*f[i-k-1][x]+f[k][x]*f[i-k-1][j-1])%MOD;
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}
