#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int b[3000005];
int sum, maxp, max2p, x, i;
int main(){
    #ifndef STDIO
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &x), sum+=x;
    for(i=1; i<=m; i++) scanf("%d", &b[i]);
    scanf("%d", &x);
    for(i=1; i<=m; i++) if(b[maxp]<b[i]) maxp=i;
    for(i=1; i<=m; i++) if(b[max2p]<b[i] and i^maxp) max2p=i;
    printf("%d\n", int(0.2*sum/n+0.3*b[max2p]+0.5*x));
    return 0;
}
