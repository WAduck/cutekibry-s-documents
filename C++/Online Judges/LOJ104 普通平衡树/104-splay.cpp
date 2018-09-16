/*
Algorithm: Splay
Time complexity: O(n log n)
*/
#include <cstdio>
#include <algorithm>
#define begin int p; for(p=root; val[p]^v; p=ch[p][v>val[p]]); splay(p);
const int SCP=682*999/6;
int far[SCP], ch[SCP][2], size[SCP], times[SCP], val[SCP], cnt, root;
inline void update(int x){ size[x]=size[ch[x][0]]+size[ch[x][1]]+times[x]; }
inline void link(int s, int f, bool d){ if(s) far[s]=f; if(f) ch[f][d]=s; }
inline void rotate(int x){
    int y=far[x], yy=far[far[x]], xx=ch[x][val[x]<val[y]];
    link(xx, y, val[x]>val[y]);
    link(y, x, val[y]>val[x]);
    link(x, yy, val[x]>val[yy]);
    update(y); update(x);
}
inline void splay(int x){
    int f, ff;
    bool d;
    while(f=far[x]){
        if(far[f] and (ch[f][1]==x)==(ch[far[f]][1]==f)) rotate(f);
        rotate(x);
    }
    root=x;
}
void ins(int v){
    int p;
    for(p=root; val[p]^v and ch[p][v>val[p]]; p=ch[p][v>val[p]]);
    if(val[p]==v){ times[p]++; size[p]++; splay(p); return; }
    size[++cnt]=times[cnt]=1; val[cnt]=v; link(cnt, p, val[cnt]>val[p]);
    splay(cnt);
}
void del(int v){
    begin;
    times[p]--; size[p]--;
    if(!times[p]){
    	if(ch[p][0] and !ch[p][1]) link(ch[p][0], 0, 0), root=ch[p][0];
    	else if(!ch[p][0] and ch[p][1]) link(ch[p][1], 0, 1), root=ch[p][1];
    	else{
        	int f, r=ch[root][1];
        	for(p=ch[p][0]; ch[p][1]; p=ch[p][1]);
        	link(ch[root][0], 0, 0);
        	splay(p);
        	link(r, root, 1);
        	update(root);
    	}
    }
}
int rank(int v){
    ins(v);
    begin;
    int ans=size[ch[p][0]]+1;
    del(v);
    return ans;
}
int invrank(int k){
    int p=root;
    while(p){
    	if(size[ch[p][0]]<k and k<=size[ch[p][0]]+times[p]) break;
        else if(k<=size[ch[p][0]]+times[p]){
            if(ch[p][0]) p=ch[p][0];
            else break;
        }
        else k-=size[ch[p][0]]+times[p], p=ch[p][1];
    }
    return val[p];
}
int before(int v){
    ins(v);
    begin;
    for(p=ch[p][0]; ch[p][1]; p=ch[p][1]);
    del(v);
    return val[p];
}
int after(int v){
    ins(v);
    begin;
    for(p=ch[p][1]; ch[p][0]; p=ch[p][0]);
    del(v);
    return val[p];
}
void midorder(int p){
    if(ch[p][0]) midorder(ch[p][0]);
    for(int i=times[p]; i; i--) printf("%d ", val[p]);
    if(ch[p][1]) midorder(ch[p][1]);
}
int main(){
    //freopen("data.in", "r", stdin);
    int i, j, n, opt, x;

    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d", &opt, &x);
        switch(opt){
            case 1: ins(x); break;
            case 2: del(x); break;
            case 3: printf("%d\n", rank(x)); break;
            case 4: printf("%d\n", invrank(x)); break;
            case 5: printf("%d\n", before(x)); break;
            case 6: printf("%d\n", after(x)); break;
        }
        #ifdef debug
        printf("#");
        midorder(root);
        putchar('\n');
        #endif
    }
    return 0;
}
