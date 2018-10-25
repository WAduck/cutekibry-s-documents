#include <cstdio>
#include <cmath>
using namespace std;
int n, sqrtn, i;
int ans;
bool vis[405];
void dfs(int p){
    if(p>n){
        ans++;
        return;
    }
    dfs(p+1);
    if(vis[p]) return;
    vis[p*p]=1;
    dfs(p+1);
    vis[p*p]=0;
}
int main(){
    #ifndef STDIO
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    #endif

    scanf("%d", &n);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
