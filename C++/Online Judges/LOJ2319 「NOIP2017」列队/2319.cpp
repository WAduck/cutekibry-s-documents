#include <cstdio>
// #define debug
using namespace std;
const int SCP=682*999/2;
typedef unsigned uint;
typedef long long int64;
typedef int64 ta64[SCP<<3];
typedef int ta[SCP<<3];
uint seed;
inline int randint(){ return (seed=seed*173+682)&0x7fffffff; }
ta lson, rson, size, rnd;
ta64 vl, vr;
int cnt;
int rt[SCP], lastrt;
int n, m, q;
int i, j, qx, qy; int64 x;
inline void up(int p){ size[p]=vr[p]-vl[p]+1+size[lson[p]]+size[rson[p]]; }
inline int maximum(int p){ while(rson[p]) p=rson[p]; return p; }
void split(int p, int &l, int &r, int k){
    if(k<=0) r=p, l=0;
    else if(size[p]==k) l=p, r=0;
    else if(k<=size[lson[p]]) r=p, split(lson[p], l, lson[p], k), up(p);
    else l=p, split(rson[p], rson[p], r, k-size[lson[p]]-(vr[p]-vl[p]+1)), up(p);
}
void merge(int &p, int l, int r){
    if(!l or !r) p=l|r;
    else if(rnd[l]<rnd[r]) p=l, merge(rson[p], rson[p], r), up(p);
    else p=r, merge(lson[p], l, lson[p]), up(p);
}
inline int64 del(int &rt, int k){
    int x, y, z;
    int64 ans;
    split(rt, x, y, k);
    z=maximum(x);
    split(x, x, z, size[x]-(vr[z]-vl[z]+1));
    k-=size[x];
    ans=vl[z]+k-1;
    if(vl[z]<=ans-1){
        cnt++;
        vl[cnt]=vl[z]; vr[cnt]=ans-1; size[cnt]=vr[cnt]-vl[cnt]+1; rnd[cnt]=randint();
        merge(x, x, cnt);
    }
    if(ans+1<=vr[z]){
        cnt++;
        vl[cnt]=ans+1; vr[cnt]=vr[z]; size[cnt]=vr[cnt]-vl[cnt]+1; rnd[cnt]=randint();
        merge(x, x, cnt);
    }
    merge(rt, x, y);
    return ans;
}
//      k
// 4567 234 1
inline int64 dellast(int k){
    int x, y, z;
    split(lastrt, x, y, k);
    split(x, x, z, k-1);
    merge(lastrt, x, y);
    return vl[z];
}
inline void ins(int &rt, int64 x){
    cnt++;
    vl[cnt]=vr[cnt]=x; size[cnt]=1; rnd[cnt]=randint();
    merge(rt, rt, cnt);
}

    #ifdef debug
    void midorder(int p){
        if(!p) return;
        int i;
        midorder(lson[p]);
        for(i=vl[p]; i<=vr[p]; i++) printf("%d ", i);
        midorder(rson[p]);
    }
    #endif

int main(){
    // freopen("data.in", "r", stdin);
    // freopen("2319.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &q);
    if(m>1){
        for(i=1; i<=n; i++){
            rt[i]=++cnt;
            vl[cnt]=(int64)(i-1)*m+1; vr[cnt]=(int64)i*m-1; size[cnt]=m-1; rnd[cnt]=randint();
        }
    }
    for(i=1; i<=n; i++){
        cnt++;
        vl[cnt]=vr[cnt]=(int64)i*m; size[cnt]=1; rnd[cnt]=randint();
        merge(lastrt, lastrt, cnt);
    }
    for(i=1; i<=q; i++){
        scanf("%d %d", &qx, &qy);
        if(qy<m){
            printf("%lld\n", x=del(rt[qx], qy));
            ins(rt[qx], dellast(qx));
            // if(i==3) midorder(rt[qx]), putchar('\n');
        }
        else
            printf("%lld\n", x=dellast(qx));
        ins(lastrt, x);

            #ifdef debug
            for(j=1; j<=n; j++) printf("# "), midorder(rt[j]), putchar('\n');
            printf("## "), midorder(lastrt), putchar('\n');
            #endif
    }
    return 0;
}
