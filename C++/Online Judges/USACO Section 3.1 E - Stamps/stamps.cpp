/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: stamps
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int i, j, n, lim;
int a[55];
unsigned char f[2000005];
int main(){
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    scanf("%d %d", &lim, &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    for(i=1; i<=2000000; i++){
        f[i]=lim;
        for(j=1; j<=n; j++) if(i-a[j]>=0) f[i]=min(f[i], f[i-a[j]]);
        f[i]++;
        if(f[i]>lim){
            printf("%d\n", i-1);
            return 0;
        }
    }
    printf("ERR\n");
    return 0;
}
