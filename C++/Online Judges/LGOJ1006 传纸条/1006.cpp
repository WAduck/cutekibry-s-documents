#include <cstdio>
using namespace std;
int f[55][55][55][55];
int a[55][55];
inline int max(int a, int b){ return (a>b)?a:b; }
inline int max4(int a, int b, int c, int d){ return max(max(max(a, b), c), d); }
int main(){
    int i, j, k, l, n, m, x, y;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) scanf("%d", &a[i][j]);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) for(k=1; k<=n; k++) for(l=1; l<=m; l++) f[i][j][k][l]=max4(f[i][j-1][k][l-1], f[i][j-1][k-1][l], f[i-1][j][k][l-1], f[i-1][j][k-1][l])+a[i][j]+((i==k and j==l)?0:a[k][l]);
    printf("%d", f[n][m][n][m]);
    return 0;
}
