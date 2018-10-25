#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
int64 a[600005], ans[600005];
int i, j, n, m;
int main(){
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    ans[0]=1e9;
    for(i=1; i<=1000; i++){
        for(j=1; j<=n; j++) ans[i]+=(a[j]+i)*(a[j]+i);
        ans[i]=min(ans[i-1], ans[i]/i);
    }
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d", &j);
        printf("%lld\n", ans[j]);
    }
    return 0;
}
