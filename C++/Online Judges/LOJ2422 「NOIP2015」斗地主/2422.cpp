#include <cstdio>
#include <cstring>
#include <algorithm>
#define cpy memcpy(c[p+1], c[p], sizeof(c[p]))
using namespace std;
const int VAL[]={14, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int c[25][17];
int n, m, T, i, x, y;
int ans;
void dfs(int p, int pre, int tot){
    int i, j, k, l;
    ans=min(ans, p+tot);
    if(p>=ans) return;
    if(!pre){ //四带二(0)
        for(i=1; i<=13; i++) if(c[p][i]>=4){
            for(j=1; j<=14; j++) if(i^j and c[p][j]){
                for(k=j; k<=14; k++) if(i^k and c[p][k]>(j==k)){
                    if(c[p][j]>=2 and c[p][k]>=((j^k)?2:4)){
                        cpy;
                        c[p+1][i]-=4;
                        c[p+1][j]-=2;
                        c[p+1][k]-=2;
                        dfs(p+1, 0, tot-8);
                    }
                    cpy;
                    c[p+1][i]-=4;
                    c[p+1][j]--;
                    c[p+1][k]--;
                    dfs(p+1, 0, tot-6);
                }
            }
        }
    }
    for(k=2; k; k--) if(pre<=3-k){ //三带多(1-2)
        for(i=1; i<=13; i++) if(c[p][i]>=3){
            for(j=1; j<=14; j++) if(i^j and c[p][j]>=k){
                cpy;
                c[p+1][i]-=3;
                c[p+1][j]-=k;
                dfs(p+1, 3-k, tot-3-k);
            }
        }
    }
    for(k=4; k>=2; k--) if(pre<=7-k){ //对牌(3~5)
        for(i=1; i<=14; i++) if(c[p][i]>=k){
            cpy;
            c[p+1][i]-=k;
            dfs(p+1, 7-k, tot-k);
        }
    }
    for(k=3; k; k--) if(pre<=9-k){ //顺子(6~8)
        for(i=1; i<=12; i++){
            for(j=i; j<=12 and c[p][j]>=k; j++) if(j-i+1>(1<<(3-k))){
                cpy;
                for(l=i; l<=j; l++) c[p+1][l]-=k;
                dfs(p+1, 9-k, tot-(j-i+1)*k);
            }
        }
    }
}
int main(){
    // freopen("2422.in", "r", stdin);
    scanf("%d %d", &T, &n);
    while(T--){
        memset(c, 0, sizeof(c));
        for(i=1; i<=n; i++){
            scanf("%d %d", &x, &y);
            c[0][VAL[x]]++;
        }
        ans=n;
        dfs(0, 0, n);
        printf("%d\n", ans);
    }
    return 0;
}
