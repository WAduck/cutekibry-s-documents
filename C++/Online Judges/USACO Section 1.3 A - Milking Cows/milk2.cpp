/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=0x7fffffff;
struct Seg{ int l, r; Seg(){} Seg(int x, int y){ l=x; r=y; } Seg operator = (const Seg b){ l=b.l; r=b.r; return *this; } };
Seg a[5005], c[5005], tseg;
int i, n, cnt;
int inmilk, outmilk;
bool segcmp(Seg a, Seg b){ if(a.l^b.l) return a.l < b.l; return a.r > b.r; }
int main(){
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d %d", &a[i].l, &a[i].r);
    sort(a+1, a+1+n, segcmp);
    a[++n]=Seg(INF, INF);
    tseg=a[1];
    for(i=2; i<=n; i++){
        if(tseg.r<a[i].l){
            // printf("# %d %d %d\n", i, tseg.l, tseg.r);
            c[++cnt]=tseg;
            tseg=a[i];
        }
        else
            tseg.r=max(tseg.r, a[i].r);
    }
    n=cnt;
    for(i=1; i<=n; i++) a[i]=c[i];
    a[0].r=a[1].l;
    for(i=1; i<=n; i++){
        inmilk=max(inmilk, a[i].r-a[i].l);
        outmilk=max(outmilk, a[i].l-a[i-1].r);
    }
    printf("%d %d\n", inmilk, outmilk);
    return 0;
}
