#include <cstdio>
using namespace std;
int a[1005][1005];
int n, m, q;
int qx, qy, x;
int i, j, k;
int main(){
    scanf("%d %d %d", &n, &m, &q);
    k=1;
    for(i=1; i<=n; i++) for(j=1; j<=m; j++, k++) a[i][j]=k;
    for(i=1; i<=q; i++){
        scanf("%d %d", &qx, &qy);
        printf("%d\n", x=a[qx][qy]);
        a[qx][qy]=0;
        for(j=qy; j<=m; j++) a[qx][j]=a[qx][j+1];
        for(j=qx; j<=n; j++) a[j][m]=a[j+1][m];
        a[n][m]=x;
    }
    return 0;
}
