/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: range
*/
#include <cstdio>
using namespace std;
int i, j, k, x, n, res;
int sum[305][305];
char ch;
int main(){
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf(" %c", &ch);
            sum[i][j]=(!(ch&1))+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(x=2; x<=n; x++){
        res=0;
        for(i=1; i+x-1<=n; i++){
            for(j=1; j+x-1<=n; j++){
                res+=!(sum[i+x-1][j+x-1]-sum[i-1][j+x-1]-sum[i+x-1][j-1]+sum[i-1][j-1]);
            }
        }
        if(res) printf("%d %d\n", x, res);
    }
    return 0;
}
