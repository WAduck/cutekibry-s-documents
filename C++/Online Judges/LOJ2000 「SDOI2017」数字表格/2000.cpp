#include <cstdio>
#include <algorithm>
#define ri register int
using namespace std;
typedef long long int64;
const int SCP=682*999*2, MOD=1e9+7;
int mu[SCP], mul[SCP], fib[SCP], invfib[SCP], mulprod[SCP], invmulprod[SCP];
int p[SCP], pn;
bool notp[SCP];
inline int qmod(int x, int mod){
    while(x<0) x+=mod;
    while(x>=mod) x-=mod;
    return x;
}
inline int qpow(int b, int p, int mod){
    ri res=1;
    while(p){
        if(p&1) res=(int64)res*b%mod;
        b=(int64)b*b%mod;
        p>>=1;
    }
    return res;
}
inline void getfunction(int n){
    ri i, j;
    // fib
    fib[1]=1;
    for(i=2; i<=n; i++) fib[i]=qmod(fib[i-1]+fib[i-2], MOD);
    // mu && prime
    mu[1]=1;
    for(i=2; i<=n; i++){
        if(!notp[i]){
            p[++pn]=i;
            mu[i]=-1;
        }
        for(j=1; i*p[j]<=n and j<=pn; j++){
            notp[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i];
            else{
                mu[i*p[j]]=0;
                break;
            }
        }
    }
    // mul
    for(i=1; i<=n; i++) mul[i]=1;
    for(i=1; i<=n; i++) invfib[i]=qpow(fib[i], MOD-2, MOD);
    for(i=1; i<=n; i++){
        for(j=1; i*j<=n; j++){
            if(mu[j]==1) mul[i*j]=(int64)mul[i*j]*fib[i]%MOD;
            else if(mu[j]==-1) mul[i*j]=(int64)mul[i*j]*invfib[i]%MOD;
        }
    }
    mulprod[0]=invmulprod[0]=1;
    for(i=1; i<=n; i++){
        mulprod[i]=(int64)mulprod[i-1]*mul[i]%MOD;
        invmulprod[i]=qpow(mulprod[i], MOD-2, MOD);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2000.in", "r", stdin);
    freopen("2000.out", "w", stdout);
    #endif

    ri i, j, T, n, m, ans;
    getfunction(1000000);
    scanf("%d", &T);
    while(T--){
        ans=1;
        scanf("%d %d", &n, &m);
        if(n>m) swap(n, m);
        for(i=1; i<=n; i=j+1){
            j=min(n, min(n/(n/i), m/(m/i)));
            // printf("%d %d %d %d\n", i, j, (int64)mulprod[j]*invmulprod[i-1]%MOD, qpow((int64)mulprod[j]*invmulprod[i-1]%MOD, (int64)(n/i)*(m/i)%(MOD-1), MOD));
            ans=(int64)ans*qpow((int64)mulprod[j]*invmulprod[i-1]%MOD, (int64)(n/i)*(m/i)%(MOD-1), MOD)%MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
