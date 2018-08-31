/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: fence9
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const double EPS=1e-8;
struct Function{
    double k, b;
    Function(){}
    Function (double x, double y){ k=x; y=b; }
    Function (double x1, double y1, double x2, double y2){
        if(x2==x1) x2+=EPS;
        $ printf("# %.3lf %3.lf\n", y2-y1, x2-x1);
        k=(y2-y1)/(x2-x1);
        if(k==0) k+=EPS;
        b=y1-k*x1;
    }
    Function operator = (Function x){ k=x.k; b=x.b; return *this; }
    double operator () (double x){ return k*x+b; }
    double when(double y){ return (y-b)/k; }
};
Function x, y;
int n, m, p, i, ans;
double l, r;
int main(){
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &p);
    $ printf("%d %d %d\n", n, m, p);
    Function x=Function(0, 0, n, m);
    Function y=Function(p, 0, n, m);
    for(i=1; i<m; i++){
        $ printf("# %.3lf %.3lf %.3lf %.3lf\n", x.k, x.b, y.k, y.b);
        r=floor(y.when(i)-EPS);
        l=ceil(x.when(i)+EPS);
        $ printf("# %d %.3lf %.3lf\n", i, l, r);
        ans+=max(0.0, r-l+1);
    }
    printf("%d\n", ans);
    return 0;
}
