/*
Algorithm: Splay
Time complexity: O(n log n)
*/
#include <cstdio>
#include <algorithm>
using std::swap;
const int SCP=682*999/6;
int val[SCP], ch[SCP][2], far[SCP], mark[SCP], size[SCP], root, cnt;
int n, m;
inline void link(int s, int f, bool d){ if(s) far[s]=f; if(f) ch[f][d]=s; }
inline void reversetree(int p){ swap(ch[p][0], ch[p][1]); mark[p]^=1; }
inline void up(int p){ if(p) size[p]=size[ch[p][0]]+size[ch[p][1]]+1; }
inline void down(int p){ if(mark[p]){ reversetree(ch[p][0]); reversetree(ch[p][1]); mark[p]=0; } }
inline void rotate(int x){
	bool xd=ch[far[x]][1]==x, yd=ch[far[far[x]]][1]==far[x];
    int y=far[x], yy=far[y], xx=ch[x][!xd];
    link(y, x, !xd);
    link(xx, y, xd);
    link(x, yy, yd);
    up(y); up(x);
}
/*
  y
 /
x
\
 xx
*/
inline void splay(int p, int to){
    while(far[p]^to){
        if(far[far[p]]^to and (val[p]>val[far[p]])==(val[far[p]]>val[far[far[p]]])) rotate(far[p]);
        rotate(p);
    }
    if(!to) root=p;
}
int find(int p, int k){
    down(p);
    if(k<=size[ch[p][0]]) return find(ch[p][0], k);
    else if(k==size[ch[p][0]]+1) return p;
    else return find(ch[p][1], k-size[ch[p][0]]-1);
}
inline void reverse(int l, int r){
    splay(find(root, r+2), 0);
    splay(find(root, l), root);
    reversetree(ch[ch[root][0]][1]);
}
inline void build(){
    int i, p;
    for(i=0; i<=n+1; i++){
        for(p=root; ch[p][1]; p=ch[p][1]);
        val[++cnt]=i; size[cnt]=1; link(cnt, p, 1);
        splay(cnt, 0);
    }
}
void midorder(int p){
    if(!p) return;
    down(p);
    midorder(ch[p][0]);
    if(val[p] and val[p]<=n) printf("%d ", val[p]);
    midorder(ch[p][1]);
}
int main(){
    int i;
    int l, r;

    scanf("%d %d", &n, &m);
    build();
    for(i=1; i<=m; i++){
         scanf("%d %d", &l, &r);
         reverse(l, r);
    }
    midorder(root);
    return 0;
}
