#include <cstdio>
#include <algorithm>
#define ri register int
#define rc register char
using namespace std;
typedef long long int64;
const int SCP=682*999*2, MOD=1e9+7;
int mu[SCP], fib[SCP], f[SCP], p[SCP], pn;
int musum[SCP], fibsum[SCP], fsum[SCP];
bool notp[SCP];

/* Read/Write */
char __buff[20];
inline void read(int &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void write(int x){ ri top=0; if(!x){ putchar('0'); return; } while(x) __buff[++top]=(x%10)|48, x/=10; while(top) putchar(__buff[top--]); }
inline void writeln(int x){ write(x); putchar('\n'); }

inline int qmod(int x, int mod){
    while(x<0) x+=mod;
    while(x>=mod) x-=mod;
    return x;
}
inline void getfib(int n){
    ri i;
    fib[0]=0; fib[1]=1;
    for(i=2; i<=n; i++) fib[i]=qmod(fib[i-1]+fib[i-2], MOD);
    for(i=1; i<=n; i++) fibsum[i]=qmod(fib[i]+fibsum[i-1], MOD);
}
inline void getmu(int n){
    ri i, j;
    mu[1]=1;
    for(i=2; i<=n; i++){
        if(!notp[i]){
            p[++pn]=i;
            mu[i]=-1;
        }
        for(j=1; j<=pn and i*p[j]<=n; j++){
            notp[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i];
            else{
                mu[i*p[j]]=0;
                break;
            }
        }
    }
    for(i=1; i<=n; i++) musum[i]=qmod(mu[i]+musum[i-1], MOD);
}
inline int fn(int n, int m){
    ri i, j, ans=0;
    for(i=1; i<=n; i++){
        j=min(n, min(n/(n/i), m/(m/i)));
        ans=qmod(ans+(int64)(n/i)*(m/i)%MOD*qmod(musum[j]-musum[i-1], MOD), MOD);
    }
    return ans;
}
inline int getans(int n, int m){
    ri i, j, ans=0;
    for(i=1; i<=n; i++){
        j=min(n, min(n/(n/i), m/(m/i)));
        ans=qmod(ans+(int64)qmod(fibsum[j]-fibsum[i-1], MOD)*fn(n/i, m/i), MOD);
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2000.in", "r", stdin);
    freopen("2000.out", "w", stdout);
    #endif

    ri t, n, m;
    ri i, j, ans;

    read(t);
    getfib(1000000);
    getmu(1000000);
    while(t--){
        read(n); read(m);
        if(n>m) swap(n, m);
        writeln(getans(n, m));
    }
    return 0;
}
