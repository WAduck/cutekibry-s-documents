#include <cstdio>
using namespace std;
const int MAX=100;
const int MAXQ=100;
unsigned seed;
inline unsigned randint(unsigned l, unsigned r){ return (seed=seed*173+682)%(r-l+1)+l; }
int n, m, q;
int main(){
    scanf("%u", &seed);
    printf("%d %d %d\n", n=randint(1, MAX), m=randint(1, MAX), q=randint(1, MAXQ));
    while(q--)
        printf("%d %d\n", randint(1, n), randint(1, m));
    return 0;
}
