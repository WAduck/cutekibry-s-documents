#include <cstdio>
#include <algorithm>
#define mid ((l+r)>>1)
#define ri register int
using namespace std;
const int SCP=682*999/3;

/* Persistable Segment Tree */
int lson[SCP*20], rson[SCP*20], sum[SCP*20];
int rt[SCP], cnt;
void ins(int &p, int fp, int l, int r, int x, int y){
    p=++cnt;
    lson[p]=lson[fp]; rson[p]=rson[fp]; sum[p]=sum[fp]+y;
    if(l==r) return;
    else if(x<=mid) ins(lson[p], lson[p], l, mid, x, y);
    else ins(rson[p], rson[p], mid+1, r, x, y);
}
int query(int p, int l, int r, int a, int b){
    if(!p or r<a or l>b) return 0;
    else if(a<=l and r<=b) return sum[p];
    else return query(lson[p], l, mid, a, b)+query(rson[p], mid+1, r, a, b);
}

/* Tree */
int pre[SCP<<1], to[SCP<<1], head[SCP], wcnt;
int far[SCP], dep[SCP], size[SCP], son[SCP], top[SCP], id[SCP], idcnt;
int root;
int n, m;
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
void dfs1(int u){
    int i, v;
    size[u]=1;
    for(i=head[u]; i; i=pre[i]) if(!dep[v=to[i]]){
        dep[v]=dep[u]+1;
        far[v]=u;
        dfs1(v);
        size[u]+=size[v];
        if(size[son[u]]<size[v]) son[u]=v;
    }
}
void dfs2(int u, int topf){
    int i, v;
    top[u]=topf;
    id[u]=++idcnt;
    if(son[u]){
        dfs2(son[u], topf);
        for(i=head[u]; i; i=pre[i]) if(!id[v=to[i]]) dfs2(v, v);
    }
}
inline void querylink(int x, int y, int rt){
    ri ans1=0, ans2=0;
    while(top[x]^top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        ans1+=id[x]-id[top[x]]+1;
        ans2+=query(rt, 1, n, id[top[x]], id[x]);
        x=far[top[x]];
    }
    if(dep[x]<dep[y]) swap(x, y);
    ans1+=id[x]-id[y]+1;
    ans2+=query(rt, 1, n, id[y], id[x]);
    printf("%d %d\n", ans1, ans2);
}

/* Main */
int main(){
    // freopen("2011.in", "r", stdin);
    // freopen("2011.out", "w", stdout);
    ri i, j, opt, x, y, c;

    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &x);
        if(!x) root=i;
        else add2edge(i, x);
    }
    dep[root]=1;
    dfs1(root);
    dfs2(root, root);
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &opt, &x);
        if(opt==1){
            scanf("%d %d", &y, &c);
            querylink(x, y, rt[(m+c-i+2<=m)?(m+c-i+2):0]);
            rt[m-i+1]=rt[m-i+2];
        }
        else
            ins(rt[m-i+1], rt[m-i+2], 1, n, id[x], 1);
    }
    return 0;
}
/*
1 Add
2 Add
3 Query 1 q+x-i+1
4


1 2 3 4 5 6 7
          2 1
*/
