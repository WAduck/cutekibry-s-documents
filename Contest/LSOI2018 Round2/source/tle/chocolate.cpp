#include <cstdio>
using namespace std;
const int SCP=682*999/6;
int n, m1, m2, i;
int t[SCP], v[SCP];
int ans=0x7fffffff;
inline void dfs(int p, int tot){
    if(tot>=ans) return;
    if(!m1 and !m2){ ans=tot; return; }
    if(p>n) return;
    dfs(p+1, tot);
    if(t[p]^2 and m1){
        m1--;
        dfs(p+1, tot+v[p]);
        m1++;
    }
    if(t[p]^1 and m2){
        m2--;
        dfs(p+1, tot+v[p]);
        m2++;
    }
}
int main(){
    freopen("chocolate.in", "r", stdin);
    freopen("chocolate.out", "w", stdout);
    scanf("%d %d %d", &n, &m1, &m2);
    for(i=1; i<=n; i++) scanf("%d %d", &t[i], &v[i]);
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
