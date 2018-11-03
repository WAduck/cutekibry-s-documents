#include <cstdio>
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
int gcd(int x, int y){
    return y?gcd(y, x%y):x;
}
int f[10005], s[10005];
int n, m, i, j, t, ans;
int main(){
    freopen("2000.in", "r", stdin);
    freopen("brust.out", "w", stdout);
    f[1]=1;
    for(i=2; i<=10000; i++) f[i]=(f[i-1]+f[i-2])%MOD;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        ans=1;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                ans=(int64)ans*f[gcd(i, j)]%MOD,
                s[gcd(i, j)]++;
        // for(i=1; i<=n; i++) printf("%d %d %d\n", i, i, s[i]);
        printf("%d\n", ans);
    }
    return 0;
}
