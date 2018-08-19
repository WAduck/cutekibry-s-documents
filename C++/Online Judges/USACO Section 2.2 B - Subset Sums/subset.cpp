/*
ID: TsukXmaru Oshawott
LANG: C++
TASK: subset
*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
int64 f[500000];
int i, j, n, sum;
int main(){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    scanf("%d", &n);
    f[0]=1;
    sum=(n+1)*n/2;
    for(i=1; i<=n; i++)
        for(j=sum; j-i+1; j--)
            f[j]+=f[j-i];
    if(sum&1) f[sum>>1]=0;
    printf("%lld\n", f[sum>>1]>>1);
    return 0;
}
