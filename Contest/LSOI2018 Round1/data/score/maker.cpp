#include <cstdio>
using namespace std;
unsigned seed;
unsigned randint(unsigned l, unsigned r){ return (seed=seed^(seed<<3)^(seed>>7)^185726312)%(r-l+1)+l; }
int main(){
    int n, m;

    scanf("%u", &seed);

    n=randint(80000, 100000);
    m=randint(80000, 100000);
    printf("%d %d\n", n, m);
    for(int i=1; i<=n; i++) printf("%d ", randint(0, 100)); putchar('\n');
    for(int i=1; i<=m; i++) printf("%d ", randint(0, 20)*5); putchar('\n');
    printf("%d\n", randint(0, 100));
    return 0;
}
