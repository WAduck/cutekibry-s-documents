/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: nuggets
*/
#include <cstdio>
using namespace std;
inline int gcd(int x, int y){ int t; while(y){ t=x%y; x=y; y=t; } return x; }
bool f[100005];
int n, m, i, j, temp, ans, x;
int main(){
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    scanf("%d", &n);
    m=100000;
    f[0]=1;
    for(i=1; i<=n; i++){
        scanf("%d", &x);
        if(x==1){
            printf("0\n");
            return 0;
        }
        for(j=x; j<=m; j++) f[j]|=f[j-x];
        temp=gcd(x, temp);
    }
    if(temp>1){
        printf("0\n");
        return 0;
    }
    for(j=m; f[j]; j--);
    printf("%d\n", j);
    return 0;
}
