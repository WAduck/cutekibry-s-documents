#include <cstdio>
#include <cmath>
using namespace std;
const int MOD=1e9+7;
int pow2[405];
int n, sqrtn, i;
int ans;
bool vis[405];
void dfs(int p, int cnt){
    if(p>sqrtn){
        ans=(ans+pow2[cnt])%MOD;
        return;
    }
    dfs(p+1, cnt);
    if(!vis[p]){
        vis[p*p]=1;
        dfs(p+1, cnt-1);
        vis[p*p]=0;
    }
}
int main(){
    #ifndef STDIO
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    #endif

    scanf("%d", &n);

    sqrtn=sqrt(n);
    pow2[0]=1;
    for(i=1; i<=n; i++) pow2[i]=(pow2[i-1]<<1)%MOD;
    dfs(2, n-sqrtn+1);
    printf("%d\n", ans);
    return 0;
}
