/*
Algorithm: Fhq Treap
Time complexity: O(n log n)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using std::swap;
const int SCP=682*999/6;
int lson[SCP], rson[SCP], rnd[SCP], val[SCP], size[SCP], cnt, root;
bool mark[SCP];
int seed;
int n, m;
inline int randint(){
    seed=(173ll*seed+682)%173682999;
    return seed;
}
inline void reversetree(int x){
    mark[x]^=1;
    swap(lson[x], rson[x]);
}
inline void up(int x){
    size[x]=size[lson[x]]+size[rson[x]]+1;
}
inline void down(int x){
    if(!mark[x]) return;
    mark[x]=0;
    reversetree(lson[x]);
    reversetree(rson[x]);
}
void merge(int &p, int l, int r){
    if(!l or !r) p=l+r;
    else if(rnd[l]<rnd[r]){ down(p=l); merge(rson[p], rson[p], r); up(p); }
    else{ down(p=r); merge(lson[p], l, lson[p]); up(p); }
}
void split(int p, int &l, int &r, int x){
    if(!x){ l=0; r=p; }
    else if(x==size[p]){ l=p; r=0; }
    else if(x<=size[lson[p]]){ down(r=p); split(lson[p], l, lson[p], x); up(p); }
    else{ down(l=p); split(rson[p], rson[p], r, x-size[lson[p]]-1); up(p); }
}
void ins(int x){
    val[++cnt]=x;
    rnd[cnt]=randint();
    size[cnt]=1;
    merge(root, root, cnt);
}
void reverse(int l, int r){
    int x, y, z;
    split(root, x, y, r);
    split(x, z, x, l-1);
    reversetree(x);
    merge(x, z, x);
    merge(root, x, y);
}
void midorder(int p){
    if(!p) return;
    down(p);
    midorder(lson[p]);
    printf("%d ", p);
    midorder(rson[p]);
}
int main(){
    int i, l, r;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) ins(i);
    for(i=1; i<=m; i++){
        scanf("%d %d", &l, &r);
        reverse(l, r);
    }
    midorder(root);
    return 0;
}
