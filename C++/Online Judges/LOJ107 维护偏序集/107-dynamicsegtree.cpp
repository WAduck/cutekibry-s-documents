/*
Algorithm: Dynamic Alloc Segtree
Time complexity: O(n log |max{Ai}-min{Ai}|)
*/
#include <cstdio>
#include <algorithm>
#define mid ((l+r)>>1)
using std::max;
const int SCP=682*999/2, LEN=1e9+1;
int lson[SCP*60], rson[SCP*60], sum[SCP*60], rt, cnt;
int m, i, opt, x;
void update(int &p, int l, int r, int x, int y){
    if(!p) p=++cnt;
    sum[p]+=y;
    if(l==r) return;
    if(x<=mid) update(lson[p], l, mid, x, y);
    else update(rson[p], mid+1, r, x, y);
}
int query(int p, int l, int r, int a, int b){
    if(!p) return 0;
    if(a<=l and r<=b) return sum[p];
    int res=0;
    if(a<=mid and lson[p]) res+=query(lson[p], l, mid, a, b);
    if(b>mid and rson[p]) res+=query(rson[p], mid+1, r, a, b);
    return res;
}
int divquery(int p, int l, int r, int x){
    if(l==r) return l;
    if(x<=sum[lson[p]]) return divquery(lson[p], l, mid, x);
    else return divquery(rson[p], mid+1, r, x-sum[lson[p]]);
}
inline void add(int x){ update(rt, 1, LEN, x, 1); }
inline void del(int x){ update(rt, 1, LEN, x, -1); }
inline int num(int x){ return (1<=x and x<=sum[rt])?divquery(rt, 1, LEN, x):0; }
inline int leq(int x){ return x?query(rt, 1, LEN, 1, x):0; }
inline int before(int x){ return num(leq(x-1)); }
// 1 1 2 3 3 3
inline int after(int x){ return num(leq(x)+1); }
// 1 1 2 2 3 3 3
// 1 1 3 3
int main(){
    // freopen("107.in", "r", stdin);
    // freopen("107.out", "w", stdout);
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &opt, &x); x++;
        switch(opt){
            case 0:{ add(x); break; }
            case 1:{ del(x); break; }
            case 2:{ printf("%d\n", num(x-1)-1); break; }
            case 3:{ printf("%d\n", leq(x-1)); break; }
            case 4:{ printf("%d\n", before(x)-1); break; }
            case 5:{ printf("%d\n", after(x)-1); break; }
        }
    }
    return 0;
}
