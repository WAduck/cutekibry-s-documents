#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
int64 a[60], b[60];
int i, cnt, n, m; bool is0;
int64 x;
inline void add(int64 x){
    int i;
    for(i=50; i and x; i--) if(x>>(i-1)&1){
        if(!a[i]){ a[i]=x; return; }
        else x^=a[i];
    }
    is0=1;
}
inline int64 querymax(int64 k){
    int64 res=0;
    int i;
    k-=is0;
    if(k>(1LL<<cnt)-1) return -1;
    for(i=cnt; i; i--){
        if(k>>(i-1)&1) res=max(res, res^b[i]);
        else res=min(res, res^b[i]);
    }
    return res;
}
inline void clear(){
    int i;
    for(i=1; i<=50; i++) if(a[i]) b[++cnt]=a[i];
}
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%lld", &x), add(x);
    clear();
    scanf("%d", &m);
    for(i=1; i<=m; i++) scanf("%lld", &x), printf("%lld\n", querymax(x));
    return 0;
}
