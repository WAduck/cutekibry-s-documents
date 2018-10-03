#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
#define ri register int
using namespace std;
const int INF=0x3f3f3f3f;
int f[12][1<<12];
int g[12][1<<12];
int w[12][12];
int main(){
    memset(f, 0x3f, sizeof(f));
    memset(g, 0x3f, sizeof(g));
    memset(w, 0x3f, sizeof(w));
    ri i, j, uv, u, v, sum, n, m, ans;
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &uv);
        u--; v--;
        w[u][v]=w[v][u]=min(w[u][v], uv);
    }
    for(i=0; i<n; i++){
        for(uv=0; !(uv>>n); uv++){
            for(j=0; j<n; j++) if(uv>>j&1)
                g[i][uv]=min(g[i][uv], w[i][j]);
        }
    }
    $ printf("%d %d %d %d\n", g[0][1], g[1][1], g[2][1], g[3][1]);
    for(i=0; i<n; i++) f[0][1<<i]=0;
    for(i=1; i<n; i++){
        for(uv=1; !(uv>>n); uv++){
            for(u=uv; u; u=(u-1)&uv) if(f[i-1][u]^INF){
                v=uv^u; //对于uv的子集u，增加v节点
                sum=0;
                for(j=0; j<n; j++) if(v>>j&1){
                    if(g[j][u]^INF) sum+=g[j][u];
                    else break;
                }
                // if(u==1 and uv==15) printf("u=%d v=%d uv=%d j=%d\n", u, v, uv, j);
                if(j>=n) f[i][uv]=min(f[i][uv], f[i-1][u]+sum*i);
            }
            $ printf("f[%d][%d]=%d\n", i, uv, f[i][uv]);
        }
    }
    ans=INF;
    for(i=0; i<n; i++) ans=min(ans, f[i][(1<<n)-1]);
    printf("%d\n", ans);
    return 0;
}
