#include <cstdio>
typedef unsigned long long uint64;
const int LIM=5;
uint64 seed;
inline uint64 randint(uint64 l, uint64 r){ return (seed=(seed<<3)^(seed>>5)^173682999500001010LL)%(r-l+1)+l; }
inline uint64 qmul(uint64 b, uint64 p, uint64 mod){
    uint64 res=0;
    while(p){
        if(p&1) res=(res+b)%mod;
        b=(b+b)%mod;
        p>>=1;
    }
    return res;
}
inline uint64 qpow(uint64 b, uint64 p, uint64 mod){
    uint64 res=1;
    while(p){
        if(p&1) res=qmul(res, b, mod);
        b=qmul(b, b, mod);
        p>>=1;
    }
    return res;
}
inline bool judge(uint64 x){
    int i;
    for(i=2; i*i<=x and i<=1000; i++) if(!(x%i)) return 0;
    return x>>1;
}
uint64 x, y;
int i;
int main(){
    // 15000*4096
    while(~scanf("%llu", &x)){
        if(x>=1000000){
            i=judge(x)?(LIM+1):0;
            if(i){
                for(i=1; i<=LIM; i++){
                    y=randint(1, x-1);
                    if(qpow(y, x-1, x)^1) break;
                }
            }
        }
        else
            i=judge(x)?(LIM+1):0;
        putchar((i>LIM)?'Y':'N');
        putchar('\n');
    }
    return 0;
}
