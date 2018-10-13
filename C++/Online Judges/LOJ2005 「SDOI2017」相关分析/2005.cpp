#include <cstdio>
#define DEBUG 0
#define $ if(DEBUG)
#define ri register int
#define mid ((l+r)>>1)
#define lson p<<1, l, mid
#define rson p<<1|1, mid+1, r
using namespace std;
const int SCP=682*999/6;
const double ZN=2773467721;
typedef double seg[SCP<<2];
double xres, yres, x2res, xyres, xavg, yavg;
int ax[SCP], ay[SCP];
double fsum[SCP], f2sum[SCP];
seg x, y, xy, x2, xadd, yadd, xfix, yfix;
inline void addtree(int p, int l, int r, double s, double t){
    xadd[p]+=s;
    yadd[p]+=t;
    xy[p]+=t*x[p]+s*y[p]+(r-l+1)*s*t;
    x2[p]+=2*s*x[p]+(r-l+1)*s*s;
    x[p]+=(r-l+1)*s;
    y[p]+=(r-l+1)*t;
}
inline void fixtree(int p, int l, int r, double s, double t){
    xadd[p]=yadd[p]=0;
    xfix[p]=s;
    yfix[p]=t;
    xy[p]=(r-l+1)*s*t+(s+t)*(fsum[r]-fsum[l-1])+f2sum[r]-f2sum[l-1];
    x2[p]=(r-l+1)*s*s+2*s*(fsum[r]-fsum[l-1])+f2sum[r]-f2sum[l-1];
    x[p]=(r-l+1)*s+fsum[r]-fsum[l-1];
    y[p]=(r-l+1)*t+fsum[r]-fsum[l-1];
}
inline void down(int p, int l, int r){
    if(xfix[p]!=ZN){
        fixtree(lson, xfix[p], yfix[p]);
        fixtree(rson, xfix[p], yfix[p]);
        xfix[p]=yfix[p]=ZN;
    }
    if(xadd[p]!=0 or yadd[p]!=0){
        addtree(lson, xadd[p], yadd[p]);
        addtree(rson, xadd[p], yadd[p]);
        xadd[p]=yadd[p]=0;
    }
}
inline void up(int p){
    x[p]=x[p<<1]+x[p<<1|1];
    y[p]=y[p<<1]+y[p<<1|1];
    xy[p]=xy[p<<1]+xy[p<<1|1];
    x2[p]=x2[p<<1]+x2[p<<1|1];
}
void build(int p, int l, int r){
    xfix[p]=yfix[p]=ZN;
    if(l^r){
        build(lson);
        build(rson);
        up(p);
    }
    else{
        x[p]=ax[l];
        y[p]=ay[l];
        xy[p]=x[p]*y[p];
        x2[p]=x[p]*x[p];
    }
}
void midorder(int p, int l, int r){
    if(l^r){
        down(p, l, r);
        midorder(lson);
        midorder(rson);
    }
    else
        printf("x[%d]=%.3lf y[%d]=%.3lf\n", l, x[p], l, y[p]);
}
void add(int p, int l, int r, int a, int b, double s, double t){
    if(a<=l and r<=b){
        addtree(p, l, r, s, t);
        return;
    }
    down(p, l, r);
    if(a<=mid) add(lson, a, b, s, t);
    if(b>mid) add(rson, a, b, s, t);
    up(p);
}
void fix(int p, int l, int r, int a, int b, double s, double t){
    if(a<=l and r<=b){
        fixtree(p, l, r, s, t);
        return;
    }
    down(p, l, r);
    if(a<=mid) fix(lson, a, b, s, t);
    if(b>mid) fix(rson, a, b, s, t);
    up(p);
}
void query(int p, int l, int r, int a, int b){
    if(a<=l and r<=b){
        xres+=x[p];
        yres+=y[p];
        xyres+=xy[p];
        x2res+=x2[p];
        return;
    }
    down(p, l, r);
    if(a<=mid) query(lson, a, b);
    if(b>mid) query(rson, a, b);
}
int main(){
    // freopen("2005.in", "r", stdin);
    // freopen("2005.out", "w", stdout);
    ri i, n, m, opt, l, r, s, t;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &ax[i]);
    for(i=1; i<=n; i++) scanf("%d", &ay[i]);
    for(i=1; i<=n; i++) fsum[i]=fsum[i-1]+i, f2sum[i]=f2sum[i-1]+(double)i*i;
    build(1, 1, n);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &opt, &l, &r);
        if(opt==1){
            xres=yres=xyres=x2res=0;
            query(1, 1, n, l, r);
            xavg=xres/(r-l+1);
            yavg=yres/(r-l+1);
            // $ printf("xres=%.3lf yres=%.3lf xyres=%.3lf x2res=%.3lf\n", xres, yres, xyres, x2res);
            if(x2res-2*xavg*xres+(r-l+1)*xavg*xavg!=0) printf("%.10lf\n", (xyres-yavg*xres-xavg*yres+(r-l+1)*xavg*yavg) /
                               (x2res-2*xavg*xres+(r-l+1)*xavg*xavg));
            else printf("%.10lf\n", ZN);
        }
        else if(opt==2){
            scanf("%d %d", &s, &t);
            add(1, 1, n, l, r, double(s), double(t));
        }
        else{
            scanf("%d %d", &s, &t);
            fix(1, 1, n, l, r, double(s), double(t));
        }
        $ midorder(1, 1, n);
    }
    return 0;
}
