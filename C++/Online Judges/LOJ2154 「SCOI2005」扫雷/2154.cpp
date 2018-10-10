#include <cstdio>
using namespace std;
typedef long long int64;
int a[10005];
int64 f[10005][2][2];
int main(){
    int n, i, j, k, l;

    scanf("%d", &n);
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);
    f[1][0][0]=1;
    f[1][1][0]=!!a[1];
    for(i=2; i<=n; i++)
        for(j=0; j<=1; j++)
            for(k=0; k<=1; k++)
                for(l=0; l<=1; l++)
                    if(((i<n and j+k<a[i]) or j+k==a[i]) and l+j+k==a[i-1])
                        f[i][j][k]+=f[i-1][k][l];
    printf("%lld", f[n][0][0]+f[n][0][1]+f[n][1][0]+f[n][1][1]);
    return 0;
}
