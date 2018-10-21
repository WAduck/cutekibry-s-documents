#include <cstdio>
#define ri register int
#define rc register char
#define seg __seg[id]
#define mark __mark[id]
#define mid ((l+r)>>1)
#define lson id, p<<1, l, mid
#define rson id, p<<1|1, mid+1, r
using namespace std;

#ifdef DEBUG
const int SCP=100;
#else
const int SCP=682*999;
#endif

/* Global */
int n, m;
int ch[SCP][3], son[SCP], far[SCP*3], v[SCP*3], id[SCP], rid[SCP], top[SCP], size[SCP], idcnt;
int __seg[3][SCP<<2], __mark[4][SCP<<2]; //seg[k][l..r]=the number of i (l<=i<=r and v[i]!=k)



/* Read */
inline void read(int &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void read(int &a, int &b, int &c){ read(a); read(b); read(c); }

/* Segtree */
inline void down(int id, int p, int l, int r){
    if(mark[p]){
        seg[p<<1]+=(mid-l+1)*mark[p];
        mark[p<<1]+=mark[p];
        seg[p<<1|1]+=(r-mid)*mark[p];
        mark[p<<1|1]+=mark[p];
        mark[p]=0;
    }
}
void build(int p, int l, int r){
    if(l^r){
        build(p<<1, l, mid);
        build(p<<1|1, mid+1, r);
        __seg[0][p]=__seg[0][p<<1]+__seg[0][p<<1|1];
        __seg[1][p]=__seg[1][p<<1]+__seg[1][p<<1|1];
        __seg[2][p]=__seg[2][p<<1]+__seg[2][p<<1|1];
    }
    else{
        __seg[0][p]=__seg[1][p]=__seg[2][p]=1;
        if(v[rid[l]]<3) __seg[v[rid[l]]][p]=0;
    }
}
void add(int id, int p, int l, int r, int a, int b, int x){
    if(id>2) return;
    if(a<=l and r<=b){
        seg[p]+=(r-l+1)*x;
        mark[p]+=x;
        return;
    }
    down(id, p, l, r);
    if(a<=mid) add(lson, a, b, x);
    if(b>mid) add(rson, a, b, x);
    seg[p]=seg[p<<1]+seg[p<<1|1];
}
inline bool query(int id, int x){
    ri p=1, l=1, r=n;
    while(l^r){
        down(id, p, l, r);
        if(x<=mid) p=p<<1, r=mid;
        else p=p<<1|1, l=mid+1;
    }
    return seg[p];
}
int divquery(int id, int p, int l, int r, int a, int b){
    // Return max{i} when l<=i<=r and seg[i]!=0
    if(id>2 or !seg[p]) return 0;
    if(l==r) return l;
    down(id, p, l, r);
    int ans;
    if(b>mid and (ans=divquery(rson, a, b))) return ans;
    else if(a<=mid and (ans=divquery(lson, a, b))) return ans;
    else return 0;
}
inline int getv(int p){
    // Get v[p]
    p=id[p];
    if(!query(0, p)) return 0;
    else if(!query(1, p)) return 1;
    else if(!query(2, p)) return 2;
    else return 3;
}
inline bool getoutput(int p){
    // Get output of v[p]
    p=id[p];
    return query(0, p) and query(1, p);
}



/* Tree */
void dfs1(int u){
    int i;
    size[u]=1;
    for(i=0; i<3; i++){
        far[ch[u][i]]=u;
        if(ch[u][i]<=n){
            dfs1(ch[u][i]);
            size[u]+=size[ch[u][i]];
            if(size[son[u]]<size[ch[u][i]]) son[u]=ch[u][i];
            v[u]+=v[ch[u][i]]>=2;
        }
        else v[u]+=v[ch[u][i]];
    }
}
void dfs2(int u, int topf){
    int i;
    top[u]=topf;
    rid[id[u]=++idcnt]=u;
    if(son[u]){
        dfs2(son[u], topf);
        for(i=0; i<3; i++) if(ch[u][i]<=n and ch[u][i]^son[u]) dfs2(ch[u][i], ch[u][i]);
    }
}
inline bool queryans01(int p){
    ri res=0;
    v[p]=1;
    p=far[p];
    // v[p]=getv(p);
    // add(v[p], 1, 1, n, id[p], id[p], 1);
    // if(p<3) add(v[p]+1, 1, 1, n, id[p], id[p], -1);
    while(p and !(res=divquery(1, 1, 1, n, id[top[p]], id[p]))){
        add(1, 1, 1, n, id[top[p]], id[p], 1);
        add(2, 1, 1, n, id[top[p]], id[p], -1);
        p=far[top[p]];
    }
    if(res){
        if(res<id[p]){
            add(1, 1, 1, n, res+1, id[p], 1);
            add(2, 1, 1, n, res+1, id[p], -1);
        }
        res=rid[res];
        v[res]=getv(res);
        add(v[res], 1, 1, n, id[res], id[res], 1);
        add(v[res]+1, 1, 1, n, id[res], id[res], -1);
    }
    return getoutput(1);
}
inline bool queryans10(int p){
    ri res=0;
    v[p]=0;
    p=far[p];
    // v[p]=getv(p);
    // add(v[p], 1, 1, n, id[p], id[p], 1);
    // add(v[p]-1, 1, 1, n, id[p], id[p], -1);
    while(p and !(res=divquery(2, 1, 1, n, id[top[p]], id[p]))){
        add(2, 1, 1, n, id[top[p]], id[p], 1);
        add(1, 1, 1, n, id[top[p]], id[p], -1);
        p=far[top[p]];
    }
    if(res){
        if(res<id[p]){
            add(2, 1, 1, n, res+1, id[p], 1);
            add(1, 1, 1, n, res+1, id[p], -1);
        }
        res=rid[res];
        v[res]=getv(res);
        add(v[res], 1, 1, n, id[res], id[res], 1);
        add(v[res]-1, 1, 1, n, id[res], id[res], -1);
    }
    return getoutput(1);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("2187.in", "r", stdin);
    freopen("2187.out", "w", stdout);
    #endif

    ri i, x;

    read(n);
    for(i=1; i<=n; i++) read(ch[i][0], ch[i][1], ch[i][2]);
    for(i=n+1; i<=3*n+1; i++) read(v[i]);
    dfs1(1);
    dfs2(1, 1);
    build(1, 1, n);
    read(m);
    for(i=1; i<=m; i++){
        read(x);
        if(v[x]) putchar(queryans10(x)|48);
        else putchar(queryans01(x)|48);
        putchar('\n');
    }
    return 0;
}
