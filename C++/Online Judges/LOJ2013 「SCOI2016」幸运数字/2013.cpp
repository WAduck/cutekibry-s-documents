#include <cstdio>
#include <cstring>
#include <algorithm>
#define ri register int
#define mid ((l+r)>>1)
#define lson p<<1, l, mid
#define rson p<<1|1, mid+1, r
using namespace std;
typedef long long int64;
const int SCP=682*999/30, LOG=60;
struct Base{
    int64 a[LOG+5], b[LOG+5];
    int size;
    Base(){ memset(a, 0, sizeof(a)); size=0; }
    Base operator = (Base b){ memcpy(a, b.a, sizeof(b.a)); memcpy((*this).b, b.b, sizeof(b.b)); size=b.size; return *this; }
    Base operator + (int64 x){
        Base res=(*this);
        if(size<=LOG){
            for(ri i=LOG; i+1; i--) if(x>>i&1){
                if(!res.a[i]) res.a[i]=res.b[++res.size]=x;
                x^=res.a[i];
            }
        }
        return res;
    }
    Base operator + (Base b){
        Base res=(*this);
        if(res.size<b.size) swap(res, b);
        if(res.size<=LOG){
            for(ri i=1; i<=b.size and res.size<=LOG; i++) res=res+b.b[i];
        }
        return res;
    }
    int64 getmax(){
        int64 x=0;
        for(ri i=LOG; i+1; i--) x=max(x, x^a[i]);
        return x;
    }
};
int pre[SCP<<1], to[SCP<<1], head[SCP], wcnt;
int dep[SCP], far[SCP], son[SCP], size[SCP], id[SCP], rid[SCP], top[SCP], idcnt;
int Log[SCP];
int n, m;
int64 v[SCP];
Base seg[SCP<<2];
void dfs1(int u){
    int i, v;
    size[u]=1;
    for(i=head[u]; i; i=pre[i]) if(!size[v=to[i]]){
        far[v]=u;
        dep[v]=dep[u]+1;
        dfs1(v);
        size[u]+=size[v];
        if(size[son[u]]<size[v]) son[u]=v;
    }
}
void dfs2(int u, int topf){
    int i;
    top[u]=topf;
    id[u]=++idcnt;
    rid[id[u]]=u;
    if(son[u]){
        dfs2(son[u], topf);
        for(i=head[u]; i; i=pre[i]) if(!id[to[i]]) dfs2(to[i], to[i]);
    }
}
void build(int p, int l, int r){
    if(l^r){
        build(lson);
        build(rson);
        seg[p]=seg[p<<1]+seg[p<<1|1];
    }
    else
        seg[p]=seg[p]+v[rid[l]];
}
inline Base query(int p, int l, int r, int a, int b){
    if(a<=l and r<=b) return seg[p];
    Base res;
    if(a<=mid) res=res+query(lson, a, b);
    if(b>mid) res=res+query(rson, a, b);
    return res;
}
inline int64 querypath(int x, int y){
    Base res;
    while(top[x]^top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        res=res+query(1, 1, n, id[top[x]], id[x]);
        x=far[top[x]];
    }
    if(dep[x]>dep[y]) swap(x, y);
    res=res+query(1, 1, n, id[x], id[y]);
    return res.getmax();
}
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2013.in", "r", stdin);
    freopen("2013.out", "w", stdout);
    #endif

    ri i, x, y;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%lld", &v[i]);
    for(i=1; i<n; i++){
        scanf("%d %d", &x, &y);
        add2edge(x, y);
    }
    dep[1]=1;
    dfs1(1);
    dfs2(1, 1);
    build(1, 1, n);
    for(i=1; i<=m; i++){
        scanf("%d %d", &x, &y);
        printf("%lld\n", querypath(x, y));
    }
    return 0;
}
