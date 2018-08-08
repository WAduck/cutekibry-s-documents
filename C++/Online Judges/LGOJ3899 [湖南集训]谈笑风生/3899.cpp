#include <cstdio>
#include <algorithm>
//#define debug
#define mid ((l+r)>>1)
using namespace std;
const int SCP=682*999/2, SPN=1<<30;
typedef long long int64;
inline void read(int &x){ register char ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void read(int &a, int &b){ read(a); read(b); }
inline void write(int64 x){ if(!x){ putchar('0'); return; } char buf[20]; register int top; for(top=0; x; x/=10) buf[++top]=(x%10)|48; while(top) putchar(buf[top--]); }
inline void writeln(int64 x){ write(x); putchar('\n'); }
/*
for update: Opt=-value, x=dep, y=id
for query: Opt=ansid|(-1?SPN:0), x=dep, y=id
*/
struct Opt{
    int opt, x, y;
    Opt(){}
    Opt(int a, int b, int c){ opt=a; x=b; y=c; }
    Opt operator = (Opt b){ opt=b.opt; x=b.x; y=b.y; return *this; }
};
Opt opt[SCP*5]; int optcnt;
bool cmp(Opt a, Opt b){
	if(a.x^b.x) return a.x<b.x;
	else if(a.opt^b.opt) return a.opt<b.opt;
	else return true;
}
int size[SCP], dep[SCP], id[SCP], idcnt;
int pre[SCP<<1], to[SCP<<1], head[SCP], wcnt;
int64 ans[SCP]; int anscnt;
int64 c[SCP];
int n, q, i, x, y, p[SCP], k[SCP];
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
inline int lowbit(int x){ return x&-x; }
inline void add(int p, int x){ for(; p<=n; p+=lowbit(p)) c[p]+=x; }
inline int64 query(int p){ register int64 ans=0; for(; p; p-=lowbit(p)) ans+=c[p]; return ans; }
void dfs(int u){
    int i, v;
    size[u]=1;
    id[u]=++idcnt;
    for(i=head[u]; i; i=pre[i]) if(!size[v=to[i]]){
        dep[v]=dep[u]+1;
        dfs(v);
        size[u]+=size[v];
    }
    if(size[u]-1) opt[++optcnt]=Opt(-(size[u]-1), dep[u], id[u]);
}
inline void push(int x1, int x2, int y1, int y2){ //x=dep, y=id
    #ifdef debug
    printf("#push: %d %d %d %d\n", x1, x2, y1, y2);
    #endif
    anscnt++;
    opt[++optcnt]=Opt(anscnt, x2, y2);
    opt[++optcnt]=Opt(anscnt|SPN, x1-1, y2);
    opt[++optcnt]=Opt(anscnt|SPN, x2, y1-1);
    opt[++optcnt]=Opt(anscnt, x1-1, y1-1);
}
int main(){
    read(n, q);
    for(i=1; i<n; i++){
        read(x, y);
        add2edge(x, y);
    }
    dep[1]=1;
    dfs(1);
    for(i=1; i<=q; i++){
        read(p[i], k[i]);
        push(dep[p[i]], dep[p[i]]+k[i], id[p[i]]+1, id[p[i]]+size[p[i]]-1);
    }
    sort(opt+1, opt+1+optcnt, cmp);
    for(i=1; i<=optcnt; i++){
        if(opt[i].opt<0) add(opt[i].y, -opt[i].opt); //update
        else{
            if(opt[i].opt>=SPN) ans[opt[i].opt^SPN]-=query(opt[i].y);
            else ans[opt[i].opt]+=query(opt[i].y);
        }
    }
    for(i=1; i<=q; i++) writeln(ans[i]+(int64)min(dep[p[i]]-1, k[i])*(size[p[i]]-1));
    return 0;
}
