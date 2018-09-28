#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned long long uint64;
inline uint64 randint(uint64 l, uint64 r){ return ((uint64)rand()*rand()*rand())%(r-l+1)+l; }
int n, x, y, i;
unsigned seed;
int main(){
    scanf("%u", &seed);
    srand(seed);
    printf("%llu %llu\n", randint(28, 32), randint(1, 50));
    return 0;
}
