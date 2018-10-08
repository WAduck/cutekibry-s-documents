#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, blocksize;
int add[250];
int a[50005];
int as[50005], bl[250], br[250];
int i, opt, l, r, x;
inline void prepare(){
    int i, j, k;
    blocksize=sqrt(n)+0.5;
    k=1;
    for(i=1; i<=n; i+=blocksize, k++) for(j=0; j<blocksize and i+j<=n; j++) as[i+j]=k;
}
inline void update(int l, int r, int x){
    int i;
    if(as[l]==as[r]){ for(i=l; i<=r; i++) a[i]+=x; return; }
    for(i=l; as[l]==as[i]; i++) a[i]+=x;
    for(i=r; as[r]==as[i]; i--) a[i]+=x;
    for(i=as[l]+1; i<as[r]; i++) add[i]+=x;
}
inline int query(int p){ return add[as[p]]+a[p]; }
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    prepare();
    for(i=1; i<=n; i++){
        scanf("%d %d %d %d", &opt, &l, &r, &x);
        if(opt==0) update(l, r, x);
        else printf("%d\n", query(r));
    }
    return 0;
}
