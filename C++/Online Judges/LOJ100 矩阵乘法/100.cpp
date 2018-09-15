#include <cstdio>
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
int n, p, m;
int i, j, k;
int a[505][505], b[505][505], c[505][505];
int main(){
    scanf("%d %d %d", &n, &p, &m);
    for(i=1; i<=n; i++) for(j=1; j<=p; j++) scanf("%d", &a[i][j]), a[i][j]=(a[i][j]+MOD)%MOD;
    for(i=1; i<=p; i++) for(j=1; j<=m; j++) scanf("%d", &b[i][j]), b[i][j]=(b[i][j]+MOD)%MOD;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            for(k=1; k<=p; k++)
                c[i][j]=(c[i][j]+(int64)a[i][k]*b[k][j])%MOD;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++) printf("%d ", c[i][j]);
        putchar('\n');
    }
    return 0;
}
