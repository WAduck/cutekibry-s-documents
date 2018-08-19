/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: concom
*/
#include <cstdio>
using namespace std;
int i, j, k, n, m, u, v, x, sum;
int w[105][105];
int f[105][105];
int q[20005], ql, qr;
bool inq[105];
int main(){
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    n=100;
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &x);
        w[u][v]+=x;
        f[u][v]+=x;
    }
    ql=1; qr=0;
    for(i=1; i<=n; i++) q[++qr]=i, inq[i]=1;
    while(ql<=qr){
        i=q[ql++];
        inq[i]=0;
        for(j=1; j<=n; j++) if(i^j and f[i][j]<=50){
            f[i][j]=w[i][j];
            for(k=1; k<=n; k++) if(f[i][k]>50) f[i][j]+=w[k][j];
            if(f[i][j]>50 and !inq[i]) q[++qr]=i, inq[i]=1;
        }
    }
    for(i=1; i<=n; i++) for(j=1; j<=n; j++) if(i^j and f[i][j]>50)
        printf("%d %d\n", i, j);
    return 0;
}
