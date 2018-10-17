#include <cstdio>
#include <algorithm>
#define y0 y00000
#define y1 y11111
using namespace std;
struct Edge{
    int u, v, w;
    bool operator < (const Edge b) const{ return w < b.w; }
};
Edge e[100005]; int etop;
int far[100005];
int n, m, i, j, u, v, w, ans;
int x0, x1, y0, y1;
char ch;
inline void init(){ for(int i=1; i<=2*n; i++) far[i]=i; }
inline int id(int x){ return (x-1)%n+1; }
int gf(int x){ return (x^far[x])?(far[x]=gf(far[x])):x; }
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<n; i++) etop++, e[etop].u=i, e[etop].v=i+1, scanf("%d", &e[etop].w);
    for(i=1; i<n; i++) etop++, e[etop].u=n+i, e[etop].v=n+i+1, scanf("%d", &e[etop].w);
    for(i=1; i<=n; i++) etop++, e[etop].u=i, e[etop].v=n+i, scanf("%d", &e[etop].w);
    sort(e+1, e+1+etop);
    for(i=1; i<=m; i++){
        scanf(" %c", &ch);
        if(ch=='C'){
            scanf("%d %d %d %d %d", &x0, &y0, &x1, &y1, &w);
            u=x0*n+y0-n;
            v=x1*n+y1-n;
            if(u>v) swap(u, v);
            for(j=1; j<=etop; j++) if(e[j].u==u and e[j].v==v) e[j].w=w;
            sort(e+1, e+1+etop);
        }
        else{
            scanf("%d %d", &y0, &y1);
            init();
            ans=0;
            for(j=1; j<=etop; j++) if(y0<=id(e[j].u) and id(e[j].u)<=y1 and
                                      y0<=id(e[j].v) and id(e[j].v)<=y1 and
                                      gf(e[j].u)^gf(e[j].v)){
                far[gf(e[j].u)]=gf(e[j].v);
                ans+=e[j].w;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
