/*
f:
O-O-O-O
  | |
O-O O-O
O-O-O-O     O-O O-O
  | |         | | |
O-O O-O  -  O-O-O O
f[lson]     f[rson]
O-O-O-O  -  O-O O-O
  | |             |
O-O O-O  -  O-O-O-O
f[lson]     fl[rson]
fr[lson]    f[rson]

fl:
O-O-O-O
      |
O-O-O O
O O-O-O  -  O O-O-O
  | |             |
O-O O-O  -  O-O-O-O
fl[lson]    fl[rson]
O O-O-O     O-O-O-O
  | |             |
O-O O-O  -  O-O-O-O
fl[lson]    f[rson]
O O-O-O  -  O-O-O-O
  |               |
O-O O-O  -  O-O-O-O
flr[lson]   f[rson]

fr:
O-O-O-O
  |
O-O O-O

flr:
O-O-O O
  |
O O-O-O

O-O-O O  -  O-O O-O
  |           |
O O-O-O  -  O-O-O-O
flr[lson]   fr[rson]
fl[lson]    flr[rson]

O-O-O-O  -  O-O-O-O
  |
O O-O-O     O-O-O-O
fl[lson]    fr[rson]

*/
#include <cstdio>
#include <algorithm>
#define mid ((l+r)>>1)
#define lson p<<1, l, mid
#define rson p<<1|1, mid+1, r
#define ri register int
#define rc register char
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const int SCP=682*999/6, INF=0x3f3f3f3f;
int fl[SCP<<2], fr[SCP<<2], f[SCP<<2], flr[SCP<<2];
int wr[3][SCP], wd[SCP];
int n, m;
int pp[50], ll[50], rr[50], top;
inline void up(int p, int l, int r){
    if(l==r){
        fl[p]=fr[p]=0;
        f[p]=wd[l];
        return;
    }
    else{
        f[p]=min(   f[p<<1]+f[p<<1|1]+min(wr[1][mid], wr[2][mid]),
                    min(f[p<<1]+fl[p<<1|1], fr[p<<1]+f[p<<1|1])+wr[1][mid]+wr[2][mid]);
        fl[p]=min(  min(flr[p<<1]+f[p<<1|1], fl[p<<1]+fl[p<<1|1])+wr[1][mid]+wr[2][mid],
                    fl[p<<1]+f[p<<1|1]+min(wr[1][mid], wr[2][mid]));
        fr[p]=min(  min(f[p<<1]+flr[p<<1|1], fr[p<<1]+fr[p<<1|1])+wr[1][mid]+wr[2][mid],
                    f[p<<1]+fr[p<<1|1]+min(wr[1][mid], wr[2][mid]));
        flr[p]=min( fl[p<<1]+fr[p<<1|1]+min(wr[1][mid], wr[2][mid]),
                    min(flr[p<<1]+fr[p<<1|1], fl[p<<1]+flr[p<<1|1])+wr[1][mid]+wr[2][mid]);
    }
}
void build(int p, int l, int r){
    if(l^r) build(lson), build(rson);
    up(p, l, r);
}
void update(int p, int l, int r, int x){
    if(l^r){
        if(x<=mid) update(lson, x);
        else update(rson, x);
    }
    up(p, l, r);
}
void query(int p, int l, int r, int a, int b){
    if(a<=l and r<=b){
        top++;
        pp[top]=p;
        ll[top]=l;
        rr[top]=r;
        return;
    }
    if(a<=mid) query(lson, a, b);
    if(b>mid) query(rson, a, b);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2186.in", "r", stdin);
    freopen("2186.out", "w", stdout);
    #endif
    ri i, j, x0, y0, x1, y1, w, ansl, ansr, anslr, ans;
    rc ch;

    scanf("%d %d", &n, &m);
    for(i=1; i<n; i++) scanf("%d", &wr[1][i]);
    for(i=1; i<n; i++) scanf("%d", &wr[2][i]);
    for(i=1; i<=n; i++) scanf("%d", &wd[i]);
    build(1, 1, n);
    for(i=1; i<=m; i++){
        $ printf("# %d\n", i);
        do ch=getchar(); while(ch<'A');
        if(ch=='C'){
            scanf("%d %d %d %d %d", &x0, &y0, &x1, &y1, &w);
            if(x0==x1) wr[x0][min(y0, y1)]=w;
            else wd[y0]=w;
            update(1, 1, n, y0);
            update(1, 1, n, y1);
        }
        else{
            scanf("%d %d", &y0, &y1);
            top=0;
            query(1, 1, n, y0, y1);
            ans=f[pp[1]];
            ansl=fl[pp[1]];
            ansr=fr[pp[1]];
            anslr=flr[pp[1]];
            for(j=2; j<=top; j++){
                x0=min( ans+f[pp[j]]+min(wr[1][rr[j-1]], wr[2][rr[j-1]]),
                        min(ans+fl[pp[j]], ansr+f[pp[j]])+wr[1][rr[j-1]]+wr[2][rr[j-1]]);
                y0=min( min(anslr+f[pp[j]], ansl+fl[pp[j]])+wr[1][rr[j-1]]+wr[2][rr[j-1]],
                        ansl+f[pp[j]]+min(wr[1][rr[j-1]], wr[2][rr[j-1]]));
                y1=min( min(ans+flr[pp[j]], ansr+fr[pp[j]])+wr[1][rr[j-1]]+wr[2][rr[j-1]],
                        ans+fr[pp[j]]+min(wr[1][rr[j-1]], wr[2][rr[j-1]]));
                x1=min( ansl+fr[pp[j]]+min(wr[1][rr[j-1]], wr[2][rr[j-1]]),
                        min(anslr+fr[pp[j]], ansl+flr[pp[j]])+wr[1][rr[j-1]]+wr[2][rr[j-1]]);
                ans=x0;
                anslr=x1;
                ansl=y0;
                ansr=y1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
