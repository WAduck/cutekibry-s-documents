/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: shopping
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int f[6][6][6][6][6];
int input[105][15];
int a[115][6], p[115];
int c[1005];
int need[6];
int n, m, i, j, k, l, o, x, y;
int main(){
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d", &input[i][1]);
        for(j=1; j<=(input[i][1]<<1); j++) scanf("%d", &input[i][j+1]);
        scanf("%d", &p[i]);
    }
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d %d", &x, &need[i], &y);
        c[x]=i;
        a[++m][i]=1;
        p[m]=y;
    }
    for(i=1; input[i][1]; i++)
        for(j=1; j<=(input[i][1]<<1); j++)
            a[i][c[input[i][j+1]]]=input[i][j+2];
    for(i=0; i<=need[1]; i++){
        for(j=0; j<=need[2]; j++){
            for(k=0; k<=need[3]; k++){
                for(l=0; l<=need[4]; l++){
                    for(o=0; o<=need[5]; o++){
                        f[i][j][k][l][o]=(i or j or k or l or o)?INF:0;
                        for(x=1; x<=m; x++){
                            if(i-a[x][1]>=0 and j-a[x][2]>=0 and k-a[x][3]>=0 and l-a[x][4]>=0 and o-a[x][5]>=0){
                                f[i][j][k][l][o]=min(f[i][j][k][l][o], f[i-a[x][1]][j-a[x][2]][k-a[x][3]][l-a[x][4]][o-a[x][5]]+p[x]);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", f[need[1]][need[2]][need[3]][need[4]][need[5]]);
    return 0;
}
