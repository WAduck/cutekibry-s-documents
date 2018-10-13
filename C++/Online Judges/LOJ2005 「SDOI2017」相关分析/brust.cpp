#include <cstdio>
using namespace std;
const double ZN=2773467721;
double x[100005], y[100005];
int n, m, opt, l, r, s, t, i, j, ax, ay;
double xavg, xres, yavg, yres;
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &ax), x[i]=ax;
    for(i=1; i<=n; i++) scanf("%d", &ay), y[i]=ay;
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &opt, &l, &r);
        if(opt==1){
            xavg=yavg=xres=yres=0;
            for(j=l; j<=r; j++) xavg+=x[j], yavg+=y[j];
            xavg/=(r-l+1);
            yavg/=(r-l+1);
            for(j=l; j<=r; j++) xres+=(x[j]-xavg)*(y[j]-yavg), yres+=(x[j]-xavg)*(x[j]-xavg);
            if(yres!=0) printf("%.10lf\n", xres/yres);
            else printf("%.10lf\n", ZN);
        }
        else if(opt==2){
            scanf("%d %d", &s, &t);
            for(j=l; j<=r; j++) x[j]+=s, y[j]+=t;
        }
        else{
            scanf("%d %d", &s, &t);
            for(j=l; j<=r; j++) x[j]=s+j, y[j]=t+j;
        }
    }
    return 0;
}
