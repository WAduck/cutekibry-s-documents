/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: fc
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
struct Vector{
    double x, y, z;
    Vector(){}
    Vector(double _x, double _y, double _z){ x=_x; y=_y; z=_z; }
    Vector operator = (Vector b){ x=b.x; y=b.y; z=b.z; return *this; }
    Vector operator * (Vector b){ return Vector(y*b.z-z*b.y, x*b.z-z*b.x, x*b.y-y*b.x); }
    double length(){ return sqrt(x*x+y*y+z*z); }
};
struct Point{
    double x, y, z;
    Point(){}
    Point(double _x, double _y, double _z){ x=_x; y=_y; z=_z; }
    Point operator = (Point b){ x=b.x; y=b.y; z=b.z; return *this; }
    Vector operator - (Point b){ return Vector(x-b.x, y-b.y, z-b.z); }
};
Point a[20005], q[20005], o; int ql, qr;
int n, m, i, j;
double res;
bool flag;
bool cmp(Point a, Point b){ return atan2(a.x-o.x, a.y-o.y) > atan2(b.x-o.x, b.y-o.y); }
int main(){
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%lf %lf", &a[i].x, &a[i].y);
    o=Point(0, 0, 0);
    sort(a+1, a+1+n, cmp);
    $ for(i=1; i<=n; i++) printf("%.6lf\n", atan2(a[i].x-o.x, a[i].y-o.y));
    ql=1, qr=0;
    for(i=1; i<=n; i++){
        while(qr-ql>=2 and ((q[qr-1]-q[qr])*(q[qr]-a[i])).z<0) qr--;
        q[++qr]=a[i];
    }
    flag=1;
    while(qr-ql>=2 and flag){
        flag=0;
        if(((q[qr-1]-q[qr])*(q[qr]-q[ql])).z<0) qr--, flag=1;
        else if(((q[qr]-q[ql])*(q[ql]-q[ql+1])).z<0) ql++, flag=1;
    }
    // sort(q+ql, q+qr+1, cmp);
    for(i=ql; i<qr; i++) res+=(q[i]-q[i+1]).length();
    res+=(q[qr]-q[ql]).length();
    printf("%.2lf\n", res);
    return 0;
}
