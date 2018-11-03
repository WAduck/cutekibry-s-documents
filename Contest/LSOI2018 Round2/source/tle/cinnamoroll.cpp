#include <cstdio>
using namespace std;
const int MOD=1e9+7;
int n, m, a, b, ans=1, i;
int main(){
    freopen("cinnamoroll.in", "r", stdin);
    freopen("cinnamoroll.out", "w", stdout);
    scanf("%d %d", &n, &m);
    a=b=n+1;
    if(m>=1) scanf("%d", &a);
    if(m>=2) scanf("%d", &b);
    for(i=2; i<n; i++) if(i%a and i%b) ans=(ans<<1)%MOD;
    printf("%d\n", ans);
}
