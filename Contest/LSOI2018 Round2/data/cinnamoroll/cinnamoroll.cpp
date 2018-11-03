#include <cstdio>
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
inline int gcd(int x, int y){ return y?gcd(y, x%y):x; }
inline int64 lcm(int x, int y){ return (int64)x*y/gcd(x, y); }
inline int qpow(int b, int p, int mod){
    int res=1;
    while(p){
        if(p&1) res=(int64)res*b%mod;
        b=(int64)b*b%mod;
        p>>=1;
    }
    return res;
}
int n, a, b, m;
int main(){
    #ifndef STDIO
    freopen("cinnamoroll.in", "r", stdin);
    freopen("cinnamoroll.out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    a=b=n+1;
    if(m>=1) scanf("%d", &a);
    if(m>=2) scanf("%d", &b);
    printf("%d\n", qpow(2, n-n/a-n/b+n/lcm(a, b)-2, MOD));
    return 0;
}
