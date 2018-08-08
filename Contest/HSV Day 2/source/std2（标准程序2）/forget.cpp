#include <cstdio>
#include <cstring>
#define mid ((l+r)>>1)
using namespace std;
inline int max(int a, int b){ return (a>b)?a:b; }
int i, j, k, l, n, m, ans, tmp;
int a[505][505], f[505][505][505];
int seg[505<<2];
inline int query(int k){
    int p=1, l=1, r=m, ans=0;
    while(l<r){
        if(k<=mid) ans=max(ans, seg[p<<1|1]), p=p<<1, r=mid;
        else ans=max(ans, seg[p<<1]), p=p<<1|1, l=mid+1;
    }
    return ans;
}
inline void update(int k, int v){
    int p=1, l=1, r=m;
    while(l<r){
        seg[p]=max(seg[p], v);
        if(k<=mid) p=p<<1, r=mid;
        else p=p<<1|1, l=mid+1;
    }
    seg[p]=max(seg[p], v);
}
int main(){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++) for(j=1; j<=n; j++) scanf("%d", &a[i][j]);
    for(i=1; i<=n; i++){
        memset(seg, 0, sizeof(seg));
        for(k=1; k<=m; k++){
            tmp=0;
            for(j=1; j<i; j++) tmp=max(tmp, f[i-1][j][k]);
            update(k, tmp);
        }
        for(j=1; j<=m; j++)
            f[i][1][j]=query(j)+a[j][1];
        for(j=2; j<=i; j++)
            for(k=1; k<=m; k++)
                f[i][j][k]=f[i-1][j-1][k]+a[k][j];
    }
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) ans=max(ans, f[n][i][j]);
    printf("%d\n", ans);
    return 0;
}
