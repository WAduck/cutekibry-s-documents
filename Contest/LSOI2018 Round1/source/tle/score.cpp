#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[105], b[3000005];
int sum, maxv, max2v, x, i;
int main(){
    #ifndef STDIO
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    #endif
    cin>>n>>m;
    for(i=1; i<=n; i++) cin>>x, sum+=x;
    for(i=1; i<=m; i++) cin>>b[i];
    cin>>x;
    for(i=1; i<=m; i++) maxv=max(maxv, b[i]);
    for(i=1; i<=m; i++) if(maxv^b[i]) max2v=max(max2v, b[i]);
    printf("%.0lf\n", 0.2*sum/n+0.3*max2v+0.5*x);
    return 0;
}
