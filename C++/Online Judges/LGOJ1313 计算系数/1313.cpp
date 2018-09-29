#include <cstdio>
using namespace std;
const int MOD=10007;
int f[1001][1001];
int a, b, k, n, m;
int i, j;
int ans=1;
int main(){
    scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
    a%=MOD;
    b%=MOD;
    for(i=0; i<=k; i++) f[i][0]=1;
    for(i=1; i<=k; i++) for(j=1; j<=k; j++) f[i][j]=(f[i-1][j]+f[i-1][j-1])%MOD;
    for(i=1; i<=n; i++) ans=(ans*a)%MOD;
    for(i=1; i<=m; i++) ans=(ans*b)%MOD;
    printf("%d\n", ans*f[k][n]%MOD);
    return 0;
}
