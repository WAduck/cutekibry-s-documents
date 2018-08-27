/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: spin
*/
#include <cstdio>
#include <algorithm>
#define $ if(0)
using namespace std;
int n[6], spd[6], a[6][6], len[6][6];
int i, j, k, t, l, r;
int main(){
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    for(i=1; i<=5; i++){
        scanf("%d %d", &spd[i], &n[i]);
        for(j=1; j<=n[i]; j++) scanf("%d %d", &a[i][j], &len[i][j]);
    }
    t=0;
    while(t<=1000){
        $ printf("t=%d\n", t);
        for(i=0; i<=359; i++){
            for(j=1; j<=5; j++){
                for(k=1; k<=n[j]; k++){
                    l=(t*spd[j]+a[j][k])%360;
                    r=l+len[j][k];
                    if((l<=i and i<=r) or i+360<=r) break;
                }
                if(k>n[j]) break;
            }
            ${
                if(t==9){
                    printf("%d %d l=%d r=%d\n", i, j, l, r);
                }
            }
            if(j>5){
                printf("%d\n", t);
                return 0;
            }
        }
        t++;
    }
    printf("none\n");
    return 0;
}
