/*
ans=Cn2+Cn3+n+1。
前几天貌似在B站的3blue1brown上面看到过（逃
*/
#include <cstdio>
using namespace std;
typedef long long int64;
const int MOD=1e9+7, INV2=500000004, INV6=166666668;
int i, ans, temp, j, n;
int qpow(int b, int p, int mod){
    int res=1;
    while(p){
        if(p&1) res=(int64)res*b%mod;
        b=(int64)b*b%mod;
        p>>=1;
    }
    return res;
}
int main(){
    freopen("melon.in", "r", stdin);
    freopen("melon.out", "w", stdout);
    for(i=1; i<=5; i++){
        scanf("%d", &n);
        if(n==1) printf("2\n");
        else if(n==2) printf("4\n");
        else if(n==3) printf("8\n");
        else printf("%d\n", ((int64)n*(n-1)%MOD*INV2+(int64)n*(n-1)%MOD*(n-2)%MOD*INV6+n+1)%MOD);
    }
    return 0;
}
