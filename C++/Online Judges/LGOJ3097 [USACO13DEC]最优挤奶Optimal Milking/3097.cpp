#include <cstdio>
#include <algorithm>
#define mid ((l+r)>>1)
#define lson p<<1, l, mid
#define rson p<<1|1, mid+1, r
using namespace std;
typedef long long int64;
const int SCP=682*999/10;
int64 f[SCP<<2][2][2], ans; //f[i][j][k]表示第i个节点，左边取/不取，右边取/不取的最大值
int a[SCP];
int i, n, m, x, y;
inline void up(int p){
    int i, j;
    for(i=0; i^2; i++)
        for(j=0; j^2; j++)
            f[p][i][j]=max(max(f[p<<1][i][0]+f[p<<1|1][0][j], f[p<<1][i][1]+f[p<<1|1][0][j]), f[p<<1][i][0]+f[p<<1|1][1][j]);
}
inline void update(int x, int y){
    int p=1, l=1, r=n;
    while(l<r){
        if(x<=mid) p=p<<1, r=mid;
        else p=p<<1|1, l=mid+1;
    }
    f[p][1][1]=y;
    for(p>>=1; p; p>>=1) up(p);
}
void build(int p, int l, int r){
    if(l==r) f[p][1][1]=a[l];
    else build(lson), build(rson), up(p);
}
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    for(i=1; i<=m; i++){
        scanf("%d %d", &x, &y);
        //printf("%d %d %d\n", i, x, y);
        update(x, y);
        //printf("# %d\n", max(max(f[1][0][0], f[1][0][1]), max(f[1][1][0], f[1][1][1])));
        ans+=max(max(f[1][0][0], f[1][0][1]), max(f[1][1][0], f[1][1][1]));
    }
    printf("%lld\n", ans);
    return 0;
}
