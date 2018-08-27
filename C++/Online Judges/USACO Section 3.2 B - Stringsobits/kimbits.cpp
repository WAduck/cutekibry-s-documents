/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: kimbits
*/
#include <cstdio>
#define $ if(0)
using namespace std;
int f[35][35], f2[35][35];
int i, j, n, m;
unsigned k;
int main(){
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    scanf("%d %d %u", &n, &m, &k);
    k--;
    // printf("%d\n", k);
    for(i=0; i<=n; i++){
        f[i][0]=f2[i][0]=1;
        $ printf("%d ", f2[i][0]);
        for(j=1; j<=i and j<=m; j++) f[i][j]=f[i-1][j]+f[i-1][j-1];
        for(j=1; j<=m; j++) f2[i][j]=f2[i][j-1]+f[i][j];
        $ putchar('\n');
    }
    $ printf("k=%d", k);
    for(i=n; i; i--){
        $ printf("\nf2[%d][%d]=%d\n", i-1, m, f2[i-1][m]);
        if(k>=f2[i-1][m]) k-=f2[i-1][m--], putchar('1');
        else putchar('0');
    }
    putchar('\n');
    return 0;
}
