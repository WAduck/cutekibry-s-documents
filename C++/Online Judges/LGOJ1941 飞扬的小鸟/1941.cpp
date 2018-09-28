#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const int INF=0x3f3f3f3f;
int lb[10005], ub[10005];
int xx[1005], yy[1005];
int up[10005], down[10005];
int *x, *y;
int i, j, k, n, m, q, ans, sum;
int main(){
    memset(ub, 0x3f, sizeof(ub));
    scanf("%d %d %d", &n, &m, &q);
    for(i=0; i<n; i++) scanf("%d %d", &up[i], &down[i]);
    for(i=1; i<=q; i++){
        scanf("%d", &j);
        scanf("%d %d", &lb[j], &ub[j]);
    }
    x=xx;
    y=yy;
    for(i=1; i<=n; i++){
        swap(x, y);
        y[0]=INF;
        for(j=1; j<=m; j++){
            if(lb[i]<j and j<ub[i]) x[j]=min((j+down[i-1]<=m)?y[j+down[i-1]]:INF,
                                            (j-up[i-1]>0)?(min(y[j-up[i-1]]+1, x[j-up[i-1]]+1)):INF);
            else x[j]=INF;
        }
        for(j=m-1; j and j+up[i-1]>=m; j--) if(j<ub[i]) x[m]=min(x[m], min(x[j]+1, y[j]+1));
        ans=INF;
        for(j=1; j<=m; j++) ans=min(ans, x[j]);
        $ printf("# %d %d\n", i, ans);
        $ for(j=1; j<=m; j++) printf("%d ", x[j]);
        $ putchar('\n');
        if(ans==INF){
            printf("0\n%d\n", sum);
            return 0;
        }
        if(ub[i]^INF) sum++;
    }
    printf("1\n%d\n", ans);
    return 0;
}
