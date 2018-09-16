#include <cstdio>
typedef unsigned long long uint64;
uint64 seed;
const uint64 INF=1e18;
inline uint64 randint(uint64 l, uint64 r){ return (seed=(seed<<3)^(seed>>5)^173682999500001010LL)%(r-l+1)+l; }
int main(){
    int i;
    for(i=1; i<=15000; i++) printf("%lld\n", 100000000000000003ll);
    return 0;
}
