#include <cstdio>
#include <algorithm>
#define ri register int
#define mid ((l+r)>>1)
#define lson p<<1, l, mid
#define rson p<<1|1, mid+1, r
using namespace std;
#ifdef DEBUG
const int SCP=100;
#else
const int SCP=682*999*3;
#endif

/* Tree */
int ch[SCP][3], far[SCP], top[SCP], size[SCP], son[SCP], id[SCP], rid[SCP], dep[SCP], idcnt;
int v[SCP];
int n, m;
void dfs1(int u){
    dep[u]=dep[far[u]]+1;
    if(ch[u][0]){
        dfs1(ch[u][0]);
        dfs1(ch[u][1]);
        dfs1(ch[u][2]);
        size[u]=size[ch[u][0]]+size[ch[u][1]]+size[ch[u][2]]+1;
        if(size[ch[u][0]]>size[ch[u][1]]) son[u]=ch[u][0];
        else son[u]=ch[u][1];
        if(size[son[u]]<size[ch[u][2]]) son[u]=ch[u][3];
        v[u]=(v[ch[u][0]]>1)+(v[ch[u][1]]>1)+(v[ch[u][2]]>1);
    }
    else
        size[u]=1, v[u]=3*v[u];
}
void dfs2(int u, int topf){
    top[u]=topf;
    id[u]=++idcnt;
    rid[id[u]]=u;
    if(son[u]){
        dfs2(son[u], topf);
        if(!id[ch[u][0]]) dfs2(ch[u][0], ch[u][0]);
        if(!id[ch[u][1]]) dfs2(ch[u][1], ch[u][1]);
        if(!id[ch[u][2]]) dfs2(ch[u][2], ch[u][2]);
    }
}

/* Segtree */
int seg1[SCP<<2], seg2[SCP<<2], mark1[SCP<<2], mark2[SCP<<2];
inline void addtree(int p, int l, int r, int x1, int x2){
    seg1[p]+=(r-l+1)*x1;
    seg2[p]+=(r-l+1)*x2;
    mark1[p]+=x1;
    mark2[p]+=x2;
}
inline void down(int p, int l, int r){
    if(mark1[p] or mark2[p]){
        addtree(lson, mark1[p], mark2[p]);
        addtree(rson, mark1[p], mark2[p]);
        mark1[p]=mark2[p]=0;
    }
}
inline void up(int p){
    seg1[p]=seg1[p<<1]+seg1[p<<1|1];
    seg2[p]=seg2[p<<1]+seg2[p<<1|1];
}
void build(int p, int l, int r){
    if(l^r){
        build(lson);
        build(rson);
        up(p);
    }
    else{
        seg1[p]=bool(v[rid[l]]^1);
        seg2[p]=bool(v[rid[l]]^2);
    }
}
void add(int p, int l, int r, int a, int b, int x1, int x2){
    if(a<=l and r<=b){
        addtree(p, l, r, x1, x2);
        return;
    }
    down(p, l, r);
    if(a<=mid) add(lson, a, b, x1, x2);
    if(b>mid) add(rson, a, b, x1, x2);
    up(p);
}
int query(int seg[], int p, int l, int r, int a, int b){
    if(!seg[p]) return 0;
    if(l==r) return l;
    int res;
    down(p, l, r);
    if(b>mid and (res=query(seg, rson, a, b))) return res;
    else if(a<=mid) return query(seg, lson, a, b);
    return 0;
}
inline int queryans(int x, bool k){
    ri res;
    v[x]=3*k;
    res=x=far[x];
    while(x and !(res=query(k?seg1:seg2, 1, 1, n, id[top[x]], id[x]))){
        add(1, 1, n, id[top[x]], id[x], k?1:-1, k?-1:1);
        v[top[x]]+=k?1:-1;
        x=far[top[x]];
    }
    if(res+1<=id[x]) add(1, 1, n, res+1, id[x], k?1:-1, k?-1:1);
    res=rid[res];
    if(res){
        if(v[res]+(k?1:-1)==1) add(1, 1, n, id[res], id[res], -1, 0);
        else if(v[res]+(k?1:-1)==2) add(1, 1, n, id[res], id[res], 0, -1);
        if(v[res]==1) add(1, 1, n, id[res], id[res], 1, 0);
        else if(v[res]==2) add(1, 1, n, id[res], id[res], 0, 1);
        v[res]+=k?1:-1;
    }
    return v[1];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2187.in", "r", stdin);
    freopen("2187.out", "w", stdout);
    #endif
    ri i, x;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d %d", &ch[i][0], &ch[i][1], &ch[i][2]);
        far[ch[i][0]]=i;
        far[ch[i][1]]=i;
        far[ch[i][2]]=i;
    }
    for(i=n+1; i<=3*n+1; i++) scanf("%d", &v[i]);
    n=3*n+1;
    dfs1(1);
    dfs2(1, 1);
    build(1, 1, n);
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d", &x);
        printf("%d\n", queryans(x, v[x]<2)>=2);
    }
    return 0;
}
