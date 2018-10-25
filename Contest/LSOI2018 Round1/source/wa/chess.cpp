#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
const int SCP=682*999;
int64 sum, powsum, ans[SCP];
int n, m, i, x;
int main(){
    #ifndef STDIO
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    #endif

    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &x);
        sum+=x;
        powsum+=(int64)x*x;
    }
    scanf("%d", &m);
    for(i=1; i<=600000; i++) ans[i]=(powsum+2*sum*i+(int64)i*i*n)/i;
    for(i=1; i<=m; i++){
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}
