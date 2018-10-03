#include <cstdio>
#include <algorithm>
using namespace std;
int h[2000020], f[2000020][2];
int i, n;
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &h[i]);
    f[1][0]=f[1][1]=1;
    for(i=2; i<=n; i++){
        f[i][0]=(h[i]>h[i-1])?(f[i-1][1]+1):f[i-1][0];
        f[i][1]=(h[i]<h[i-1])?(f[i-1][0]+1):f[i-1][1];
    }
    printf("%d\n", max(f[n][0], f[n][1]));
    return 0;
}
