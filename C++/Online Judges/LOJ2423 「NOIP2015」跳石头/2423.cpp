#include <cstdio>
using namespace std;
int i, n, m;
int l, r, mid;
int a[50005];
inline int f(int x){ //令跳跃距离>=x时最少移走的石头数量
    int i, j, cnt=0;
    for(i=2, j=1; i<=n; i++){
        if(a[i]-a[j]<x) cnt++;
        else j=i;
    }
    return cnt;
}
int main(){
    scanf("%d %d %d", &i, &n, &m);
    a[n+2]=i;
    a[1]=0;
    for(i=2; i<=n+1; i++) scanf("%d", &a[i]);
    n+=2;
    l=1;
    r=a[n];
    while(l<r){
        mid=(l+r+1)>>1;
        if(f(mid)<=m) l=mid;
        else r=mid-1;
    }
    printf("%d\n", l);
    return 0;
}
