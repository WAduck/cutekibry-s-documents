/*
Algorithm: Fhq Treap
Time complexity: O(n log n)
*/
#include <cstdio>
using namespace std;
const int SCP=682*999/6, SPN=682999173;
int val[SCP], size[SCP], times[SCP], lson[SCP], rson[SCP], rnd[SCP], rt, cnt;
int x, y, z, ans, i, j, k, l, r, n, m, rk, p, opt;
int seed=SPN>>1;
inline int find(int p, int x){ for(; val[p]^x and p; p=(x<val[p])?lson[p]:rson[p]); return p; }
inline void down(int p){ return; }
inline void up(int p){ size[p]=size[lson[p]]+times[p]+size[rson[p]]; }
void split(int p, int &l, int &r, int k){
    if(k<=0) l=0, r=p;
    else if(k==size[p]) l=p, r=0;
    else if(k<=size[lson[p]]) down(r=p), split(lson[p], l, lson[p], k), up(p);
    else down(l=p), split(rson[p], rson[p], r, k-size[lson[p]]-times[p]), up(p);
}
/*
        5
       / \       4
      3  7
*/
void merge(int &p, int l, int r){
    if(!l or !r) p=l|r;
    else if(rnd[l]<rnd[r]) down(p=l), merge(rson[p], rson[p], r), up(p);
    else down(p=r), merge(lson[p], l, lson[p]), up(p);
}
int leq(int p, int x){
    if(!p) return 0;
    else if(x==val[p]) return size[lson[p]]+times[p];
    else if(x<val[p]) return leq(lson[p], x);
    else return size[lson[p]]+times[p]+leq(rson[p], x);
}
inline void ins(int k){
    rk=leq(rt, k);
    split(rt, x, y, rk);
    if(p=find(x, k)){
        split(x, z, x, rk-times[p]);
        size[p]++; times[p]++;
        merge(x, z, x);
    }
    else{
        val[++cnt]=k;
        rnd[cnt]=seed=(seed*173LL+682)%SPN;
        size[cnt]=times[cnt]=1;
        merge(x, x, cnt);
    }
    merge(rt, x, y);
}
inline void del(int k){
    rk=leq(rt, k);
    split(rt, x, y, rk);
    if(!(p=find(x, k))) return;
    split(x, z, x, rk-times[p]);
    size[p]--; times[p]--;
    if(times[p]) merge(x, z, x), merge(rt, x, y);
    else merge(rt, z, y);
}
inline int invrank(int k){
    split(rt, x, y, k);
    for(p=x; rson[p]; p=rson[p]);
    merge(rt, x, y);
    return val[p];
}
inline int before(int k){
    rk=leq(rt, k-1);
    split(rt, x, y, rk);
    for(p=x; rson[p]; p=rson[p]);
    merge(rt, x, y);
    return val[p];
}
inline int after(int k){
    rk=leq(rt, k);
    split(rt, x, y, rk);
    for(p=y; lson[p]; p=lson[p]);
    merge(rt, x, y);
    return val[p];
}
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d", &opt, &x);
        switch(opt){
            case 1:{ ins(x); break; }
            case 2:{ del(x); break; }
            case 3:{ printf("%d\n", leq(rt, x-1)+1); break; }
            case 4:{ printf("%d\n", invrank(x)); break; }
            case 5:{ printf("%d\n", before(x)); break; }
            case 6:{ printf("%d\n", after(x)); break; }
        }
    }
    return 0;
}
