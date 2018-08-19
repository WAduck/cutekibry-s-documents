/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: sort3
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int SCP=682*999/600;
int a[SCP], b[SCP], c[5][5];
int i, j, k, n, ans, temp;
int main(){
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        c[a[i]][0]++;
    }
    for(i=j=1; i<=3; i++)
        while(c[i][0]--) b[j++]=i;
    for(i=1; i<=n; i++)
        c[b[i]][a[i]]++;
    for(i=1; i<=3; i++){
        for(j=1; j<=3; j++) if(i^j){
            temp=min(c[i][j], c[j][i]);
            c[i][j]-=temp;
            c[i][i]+=temp;
            c[j][i]-=temp;
            c[j][j]+=temp;
            ans+=temp;
        }
    }
    for(i=1; i<=3; i++) if(i^1){
        for(j=1; j<=3; j++) if(j^2 and i^j){
            for(k=1; k<=3; k++) if(k^3 and i^k and j^k){
                temp=min(min(c[1][i], c[2][j]), c[3][k]);
                c[1][1]+=temp;
                c[1][i]-=temp;
                c[2][2]+=temp;
                c[2][j]-=temp;
                c[3][3]+=temp;
                c[3][k]-=temp;
                ans+=temp<<1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
