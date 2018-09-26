#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point{
    int x, y, z;
    Point(int _x=0, int _y=0, int _z=0){ x=_x; y=_y; z=_z; }
    Point operator = (Point _p){ x=_p.x; y=_p.y; z=_p.z; return *this; }
};
inline double dis(Point a, Point b){ return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)+pow(a.z-b.z, 2)); }
int T, n, h, r, i, j;
bool flag;
Point a[1005];
int f[1005], size[1005];
inline int gf(int x){ return (x^f[x])?(f[x]=gf(f[x])):x; }
inline void merge(int x, int y){
    if(size[x]>size[y]) swap(x, y);
    f[x]=y;
    size[y]+=size[x];
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &n, &h, &r);
        for(i=1; i<=n; i++) scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
        for(i=1; i<=n; i++) f[i]=i, size[i]=1;
        for(i=1; i<n; i++) for(j=i+1; j<=n; j++) if(dis(a[i], a[j])<=2*r) merge(gf(i), gf(j));
        flag=0;
        for(i=1; i<=n and !flag; i++) if(a[i].z<=r)
            for(j=1; j<=n and !flag; j++) if(h-a[j].z<=r and gf(i)==gf(j))
                flag=1;
        printf(flag?"Yes\n":"No\n");
    }
    return 0;
}
