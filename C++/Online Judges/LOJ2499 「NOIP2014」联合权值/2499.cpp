#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int CP=682*999/3, MOD=10007;
int pre[CP<<1], to[CP<<1], head[CP], wcnt;
int w[CP], f[CP], maxf[CP];
int stk[CP], top;
int far[CP];
int n, m, i, u, v;
int maxans, ans;
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
inline void dfs(int u){
    int i, j, v, m1, m2, sum;
    for(i=head[u]; i; i=pre[i]) if(!far[v=to[i]]){
        far[v]=u;
        dfs(v);
        f[u]=(f[u]+w[v])%MOD;
        maxf[u]=max(maxf[u], w[v]);
        ans=(ans+w[u]*f[v]*2)%MOD;
        maxans=max(maxans, w[u]*maxf[v]);
    }
    top=0;
    for(i=head[u]; i; i=pre[i]) if(!(far[v=to[i]]^u)) stk[++top]=v;
    if(top==1) return;
    m1=1; for(i=2; i<=top; i++) if(w[stk[m1]]<w[stk[i]]) m1=i;
    m2=(m1^1)?1:2; for(i=1; i<=top; i++) if(w[stk[m2]]<w[stk[i]] and i^m1) m2=i;
    maxans=max(maxans, w[stk[m1]]*w[stk[m2]]);
    sum=0;
    for(i=1; i<=top; i++) sum=(sum+w[stk[i]])%MOD;
    for(i=1; i<=top; i++) ans=(ans+w[stk[i]]*(sum-w[stk[i]]+MOD))%MOD;
}
int main(){
    scanf("%d", &n);
    for(i=1; i<n; i++){
        scanf("%d %d", &u, &v);
        add2edge(u, v);
    }
    for(i=1; i<=n; i++) scanf("%d", &w[i]);
    far[1]=1;
    dfs(1);
    printf("%d %d", maxans, ans%MOD);
    return 0;
}
