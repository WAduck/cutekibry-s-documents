#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 INF=0x7fffffffffffffffll;
inline int64 max(int64 a, int64 b){ return (a>b)?a:b; }
int n, a[35];
int64 f[35][35];
int fk[35][35];
void midorder(int x, int y){
    if(fk[x][y]){
        printf("%d ", fk[x][y]);
        midorder(x, fk[x][y]-1);
        midorder(fk[x][y]+1, y);
    }
    else if(x<=y)
        printf("%d " , x);
}
int main(){
    int i, j, k, x;

    scanf("%d", &n);
    for(i=1; i<=n; i++){ scanf("%d", &a[i]); f[i][i]=a[i]; }
    for(x=1; x<n; x++){
        for(i=1, j=i+x; j<=n; i++, j++){
            f[i][j]=~INF;
            for(k=i; k<=j; k++){
                if(f[i][j]<max(1, f[i][k-1])*max(1, f[k+1][j])+a[k]){
                    f[i][j]=max(1, f[i][k-1])*max(1, f[k+1][j])+a[k];
                    fk[i][j]=k;
                }
            }
        }
    }
    printf("%lld\n", f[1][n]);
    midorder(1, n);
    return 0;
}
