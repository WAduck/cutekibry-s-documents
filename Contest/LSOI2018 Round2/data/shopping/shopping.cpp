#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a, b, i, j, k, l, sum, ans;
int m[105], d[105], f[105], p[105][1005], v[105][1005];
int main(){
    #ifndef STDIO
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &a, &b);
    for(i=1; i<n; i++) scanf("%d", &d[i]);
    for(i=1; i<=n; i++){
        scanf("%d", &m[i]);
        for(j=1; j<=m[i]; j++) scanf("%d %d", &p[i][j], &v[i][j]);
    }
    ans=0x7fffffff;
    for(i=1; i<=n; i++){
        memset(f, 0, sizeof(f));
        sum=-d[i-1];
        for(j=i; j<=n and f[a]<b; j++){
            sum+=d[j-1];
            for(k=1; k<=m[j]; k++){
                for(l=a; l>=p[j][k]; l--)
                    f[l]=max(f[l], f[l-p[j][k]]+v[j][k]);
            }
        }
        if(f[a]>=b) ans=min(ans, sum);
    }
    if(ans^0x7fffffff) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
