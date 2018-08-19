/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: money
*/
#include <cstdio>
using namespace std;
typedef long long int64;
int64 f[10005];
int n, m, i, j, v;
int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    f[0]=1;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%d", &v);
        for(j=v; j<=m; j++) f[j]+=f[j-v];
    }
    printf("%lld\n", f[m]);
    return 0;
}
