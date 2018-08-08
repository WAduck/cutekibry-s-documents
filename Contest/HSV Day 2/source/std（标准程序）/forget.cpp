#include <cstdio>
using namespace std;
inline int max(int a, int b){ return (a>b)?a:b; }
int i, j, k, l, n, m, ans;
int a[55][55], f[55][55][55];
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++) for(j=1; j<=n; j++) scanf("%d", &a[i][j]);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            for(k=1; k<i; k++)
                for(l=1; l<=m; l++) if(j^l)
                    f[i][1][j]=max(f[i][1][j], f[i-1][k][l]);
            f[i][1][j]+=a[j][1];
        }
        for(j=2; j<=i; j++)
            for(k=1; k<=m; k++)
                f[i][j][k]=f[i-1][j-1][k]+a[k][j];
    }
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) ans=max(ans, f[n][i][j]);
    printf("%d\n", ans);
    return 0;
}
