/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: cowtour
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int64;
const int SCP=800;
const double INF=1e12;
double w[SCP][SCP], f[SCP], ans, ori;
int x[SCP], y[SCP];
int i, j, k, l, n, m, u, v, tx, ty, a, b;
double tdis;
char ch;
inline double dis(int x1, int y1, int x2, int y2){ return sqrt((int64)(x2-x1)*(x2-x1)+(int64)(y2-y1)*(y2-y1)); }
int main(){
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d %d", &x[i], &y[i]);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf(" %c", &ch);
            if(ch&1) w[i][j]=dis(x[i], y[i], x[j], y[j]);
            else w[i][j]=INF;
        }
        w[i][i]=0;
    }
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                w[i][j]=min(w[i][j], w[i][k]+w[k][j]);

    // for(i=1; i<=n; i++){
    //     for(j=1; j<=n; j++)
    //         printf("%3.lf ", w[i][j]);
    //     putchar('\n');
    // }

    for(i=1; i<=n; i++) for(j=1; j<=n; j++) if(w[i][j]<INF) f[i]=max(f[i], w[i][j]), ori=max(f[i], ori);
    ans=INF;
    for(i=1; i<=n; i++) for(j=i+1; j<=n; j++) if(w[i][j]==INF) ans=min(ans, f[i]+f[j]+dis(x[i], y[i], x[j], y[j]));
    printf("%.6lf\n", max(ans, ori));
    return 0;
}
