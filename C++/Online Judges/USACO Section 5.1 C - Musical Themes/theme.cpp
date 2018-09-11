/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: theme
*/
#include <cstdio>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
typedef unsigned long long uint64;
const int BASE=173, MAXV=88;
uint64 pp[5001], sum[5001][MAXV];
int a[5001];
int i, j, n, ans;
inline int qpow(int b, int p, int mod){
    int res=1;
    while(p){
        if(p&1) res=(uint64)res*b%mod;
        b=(uint64)b*b%mod;
        p>>=1;
    }
    return res;
}
uint64 f(int l, int r){ return sum[r][MAXV-a[l]]-sum[l-1][MAXV-a[l]]*pp[r-l+1]; }
int main(){
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
    scanf("%d", &n);
    pp[0]=1;
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        pp[i]=pp[i-1]*BASE;
        for(j=0; j<MAXV; j++) sum[i][j]=sum[i-1][j]*BASE+a[i]+j;
    }
    ${
        for(i=0; i<MAXV; i++){
            for(j=1; j<=n; j++) printf("%llu ", sum[j][i]);
            putchar('\n');
        }
        printf("%llu %llu\n", f(1,2), f(4,5));
    }
    ans=4;
    for(i=1; i+ans*2+1<=n; i++){
        while(1){
            for(j=i+ans+1; j+ans<=n and f(i, i+ans)^f(j, j+ans); j++);
            if(j+ans>n) break;
            ans++;
        }
    }
    printf("%d\n", (ans==4)?0:ans);
    return 0;
}
