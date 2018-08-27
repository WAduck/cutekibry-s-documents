/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: ratios
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[5][5];
inline int gcd(int x, int y){
    if(!x or !y) return 1;
    int t;
    while(t=x%y) x=y, y=t;
    return y;
}
int i, j, k, x, y, z, t, ans;
inline int judge(int i, int j, int k){
    x=a[1][1]*i+a[2][1]*j+a[3][1]*k;
    y=a[1][2]*i+a[2][2]*j+a[3][2]*k;
    z=a[1][3]*i+a[2][3]*j+a[3][3]*k;
    if(x%a[0][1]) return 0;
    t=x/a[0][1];
    if(a[0][1]*t==x and a[0][2]*t==y and a[0][3]*t==z) return t;
    return 0;
}
int main(){
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    for(i=1; i<=3; i++) scanf("%d", &a[0][i]);
    for(i=1; i<=3; i++) for(j=1; j<=3; j++) scanf("%d", &a[i][j]);
    for(i=0; i<=100; i++){
        for(j=0; j<=100; j++){
            for(k=0; k<=100; k++){
                if(ans=judge(i, j, k)){
                    printf("%d %d %d %d\n", i, j, k, ans);
                    return 0;
                }
            }
        }
    }
    printf("NONE\n");
    return 0;
}
