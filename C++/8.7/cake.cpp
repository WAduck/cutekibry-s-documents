/*
设蛋糕美味值的序列为a。
很容易发现，a的顺序无关。
因此将a排序一遍。
设f[i][j]表示选择前i个 总和为j的方案数。
f[i][j]=f[i-1][j]+sum{f[x-1][j-a[y]+a[x]]} (1<=x<y<=i, a[y]<=j+a[x])
由于共有O(nk)个状态，每个状态转移为O(n^2)，加上排序，所以时间复杂度为O(n^3k+nlogn)。
再考虑一下？
...时间限制写不下了，直接脑补O(n^2k+nlogn)做法吧。
*/
#include <cstdio>
#include <algorithm>
//#define debug
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
int a[173<<1];
int f[173<<1][682*999/600];
int i, ans, temp, j, n, x, k;
int main(){
    freopen("cake.in", "r", stdin);
    freopen("cake.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);

    f[0][0]=1;
    for(i=1; i<=n; i++){
        for(j=0; j<=k; j++){
            f[i][j]=f[i-1][j];
            for(x=1; x<i; x++) if(j+a[x]-a[i]>=0) f[i][j]=(f[i][j]+f[x-1][j+a[x]-a[i]])%MOD;
        }
    }
    for(j=0; j<=k; j++) ans=(ans+f[n][j])%MOD;
    printf("%d\n", ans);
    return 0;
}
