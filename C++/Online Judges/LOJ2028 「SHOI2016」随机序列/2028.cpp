#include <cstdio>
#define ri register int
#define mid ((l+r)>>1)
using namespace std;
typedef long long int64;
const int MOD=1e9+7, SCP=682*999/6;
int n, m;
int f[SCP];
int seg[SCP<<2], prod[SCP<<2];
inline int qmod(int x, int mod){
    while(x>=mod) x-=mod;
    return x;
}
inline void getfunction(int n){
    ri i;
    f[0]=1;
    for(i=1; i<=n; i++) f[i]=(unsigned)f[i-1]*3%MOD;
    for(i=0; i<=n; i++) f[i]=qmod(f[i]<<1, MOD);
}
inline void update(int x, int k){
    ri p=1, l=1, r=n;
    while(l^r){
        if(x<=mid) p=p<<1, r=mid;
        else p=p<<1|1, l=mid+1;
    }
    prod[p]=k;
    if(x^n) seg[p]=(int64)f[n-x-1]*k%MOD;
    else seg[p]=k;
    for(p>>=1; p; p>>=1){
        prod[p]=(int64)prod[p<<1]*prod[p<<1|1]%MOD;
        seg[p]=(seg[p<<1]+(int64)prod[p<<1]*seg[p<<1|1])%MOD;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2028.in", "r", stdin);
    freopen("2028.out", "w", stdout);
    #endif

    ri i, x, y;

    getfunction(100000);
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &x), update(i, x);
    for(i=1; i<=m; i++){
        scanf("%d %d", &x, &y);
        update(x, y);
        printf("%d\n", seg[1]);
    }
    return 0;
}
