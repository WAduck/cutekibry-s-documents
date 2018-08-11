/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: pprime
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int CP=682*999;
const int POW10[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int ans[CP], cnt;
int n;
int a, b;
int i;
inline bool judge(int x){
    int i;
    for(i=2; i*i<=x; i++) if(!(x%i)) return false;
    return true;
}
void dfs(int i, int j, int x){
    if(i>j){
        if(judge(x) and a<=x and x<=b) ans[++cnt]=x;
        return;
    }
    for(int k=0; k<=9; k++) if(k or x)
        dfs(i+1, j-1, x+POW10[i]*k+((i^j)?(POW10[j]*k):0));
}
int main(){
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    scanf("%d %d", &a, &b);
    for(i=2; i<=9; i++) if(judge(i) and a<=i and i<=b) ans[++cnt]=i;
    if(a<=11 and 11<=b) ans[++cnt]=11;
    for(i=2; i<=6; i+=2) dfs(0, i, 0);
    sort(ans+1, ans+1+cnt);
    for(i=1; i<=cnt; i++) printf("%d\n", ans[i]);
    return 0;
}
