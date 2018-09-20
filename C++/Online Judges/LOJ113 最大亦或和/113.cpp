#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
int64 a[65];
int64 x;
int n, i;
inline void add(int64 x){
    int i;
    for(i=60; x; i--) if((x>>(i-1))&1){
        if(!a[i]) a[i]=x;
        x^=a[i];
    }
}
inline int64 querymax(){
    int i;
    int64 res=0;
    for(i=60; i; i--) res=max(res, res^a[i]);
    return res;
}
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%lld", &x);
        add(x);
    }
    printf("%lld\n", querymax());
    return 0;
}
