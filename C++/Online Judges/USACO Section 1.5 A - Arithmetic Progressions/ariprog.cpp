/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: ariprog
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/20, CP=682*999;
struct Seq{
    int x, y;
    Seq(){}
    Seq(int a, int b){ x=a; y=b; }
    Seq operator = (Seq b){ x=b.x; y=b.y; return *this; }
};
bool cmp(Seq a, Seq b){ if(a.y^b.y) return a.y<b.y; return a.x<b.x; }
Seq ans[SCP]; int cnt;
int a[SCP], an;
int c[CP];
int i, j, k, n, m, maxv;
int main(){
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(i=0; i<=m; i++) for(j=i; j<=m; j++) c[i*i+j*j]=1;
    maxv=m*m<<1;
    for(i=0; i<=maxv; i++) if(c[i]) a[++an]=i;
    for(i=1; i<=an; i++){
        for(j=i+1; j<=an and a[i]+(a[j]-a[i])*(n-1)<=maxv; j++){
            for(k=1; k<=n and c[a[i]+(a[j]-a[i])*(k-1)]; k++);
            if(k>n) ans[++cnt]=Seq(a[i], a[j]-a[i]);
        }
    }
    sort(ans+1, ans+1+cnt, cmp);
    for(i=1; i<=cnt; i++) printf("%d %d\n", ans[i].x, ans[i].y);
    if(!cnt) printf("NONE\n");
    return 0;
}
