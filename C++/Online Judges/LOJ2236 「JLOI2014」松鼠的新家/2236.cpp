#include <cstdio>
#include <algorithm>
#define lson p<<1, l, (l+r)>>1
#define rson p<<1|1, ((l+r)>>1)+1, r
using namespace std;
typedef long long int64;
const int NEKO=300005;
int fa[NEKO], son[NEKO], size[NEKO], dep[NEKO], top[NEKO], id[NEKO], cnt;
int pre[NEKO<<1], to[NEKO<<1], head[NEKO], wn;
int64 sum[NEKO];
int q[NEKO];
int pos[NEKO];
int n, m;
void addedge(int a, int b){
    pre[++wn]=head[a];
    head[a]=wn;
    to[wn]=b;
}

void add(int a, int b, int c){
    sum[a]+=c;
    sum[b+1]-=c;
}

void dfs1(int p){
    int i, j;
    size[p]=1;
    for(i=head[p]; i; i=pre[i]) if(!size[j=to[i]]){
        fa[j]=p;
        dep[j]=dep[p]+1;
        dfs1(j);
        if(size[son[p]]<size[j])
            son[p]=j;
    }
}
void dfs2(int p, int topf){
    int i, j;
    id[p]=++cnt;
    top[p]=topf;
    if(son[p]){
        dfs2(son[p], topf);
        for(i=head[p]; i; i=pre[i]) if(!top[j=to[i]])
            dfs2(j, j);
    }
}
void pathadd(int x, int y){
    while(top[x]^top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        add(id[top[x]], id[x], 1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x, y);
    add(id[x], id[y], 1);
}
int main(){
    int i, j, k;

    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &q[i]);
    for(i=1; i<n; i++){
        scanf("%d %d", &j, &k);
        addedge(j, k);
        addedge(k, j);
    }
    dep[q[1]]=1;
    dfs1(q[1]);
    dfs2(q[1], q[1]);
    for(i=1; i<n; i++)
        pathadd(q[i], q[i+1]);
    add(2, n, -1);
    for(i=2; i<=n; i++) sum[i]+=sum[i-1];
    for(i=1; i<=n; i++) printf("%lld\n", sum[id[i]]);
    return 0;
}
