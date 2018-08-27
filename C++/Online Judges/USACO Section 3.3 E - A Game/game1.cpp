/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: game1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int SCP=682*999/6000;
int f[SCP][SCP], a[SCP];
int i, j, k, x, n, sum;
int main(){
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i]), sum+=a[i];
    for(i=1; i<=n; i++) f[i][i]=a[i];
    for(x=1; x<n; x++){
        for(i=1, j=1+x; j<=n; i++, j++){
            f[i][j]=max(a[i]-f[i+1][j], a[j]-f[i][j-1]);
        }
    }
    printf("%d %d\n", (sum+f[1][n])>>1, (sum-f[1][n])>>1);
    return 0;
    // x+y=sum, x-y=f[1][n]
    // x=f[1][n]+y
    // y=(sum-f[1][n])/2
    // y=x-f[1][n]
    // x=(sum+f[1][n]).2
}
