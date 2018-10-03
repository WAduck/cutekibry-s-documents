#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int g[500];
int f[1<<18];
int q[1<<20];
double x[20], y[20];
const double EPS=1e-7;
int n, top;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
        register int i, j, k, ql, qr;
        register double a, b;

        scanf("%d %d", &n, &i);
        top=0;
        ql=1, qr=0;
        for(i=1; i<=n; i++) scanf("%lf %lf", &x[i], &y[i]);
        for(i=1; i<=n; i++){
            f[g[++top]=1<<i>>1]=1;
            q[++qr]=1<<i>>1;
        }
        for(i=1; i<=n; i++) for(j=i+1; j<=n; j++){
            if(x[i]==0 or x[j]==0 or (x[i]-x[j])==0) continue;
            a=(y[i]*x[j]/x[i]-y[j])/(x[i]-x[j])/x[j];
            if(a>=0) continue;
            top++;
            b=y[j]/x[j]-a*x[j];
            for(k=1; k<=n; k++) if(fabs(y[k]-a*x[k]*x[k]-b*x[k])<=EPS)
                g[top]|=(1<<k>>1);
            f[g[top]]=1;
            q[++qr]=g[top];
        }
        while(!f[(1<<n)-1]){
            i=q[ql++];
            for(j=1; j<=top; j++) if(!f[i|g[j]]){
                f[i|g[j]]=f[i]+1;
                q[++qr]=i|g[j];
            }
        }
        printf("%d\n", f[(1<<n)-1]);
    }
    return 0;
}
