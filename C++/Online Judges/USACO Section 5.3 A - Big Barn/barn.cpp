/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: barn
*/
#include <cstdio>
using namespace std;
int sum[1005][1005];
int i, j, n, m, x, y, ans;
int main(){
    freopen("barn.in", "r", stdin);
    freopen("barn.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &x, &y);
        sum[x][y]++;
    }
    for(i=1; i<=n; i++) for(j=1; j<=n; j++) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    for(i=1; i+ans<=n; i++){
        for(j=1; j+ans<=n; j++){
            while(i+ans<=n and j+ans<=n and !(sum[i+ans][j+ans]-sum[i-1][j+ans]-sum[i+ans][j-1]+sum[i-1][j-1]))
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
