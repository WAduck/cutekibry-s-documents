/*
Algorithm: Simulate Anneal
Time complexity: O(???)
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define DEBUG 0
#define $ if(DEBUG)
#define ri register int
#define rd register double
using namespace std;
const int INF=0x3f3f3f3f, SATIMES=150;
const double DELTA=0.99, T0=20000, T1=0.1;
inline int randint(int l, int r){ return rand()%(r-l+1)+l; }
inline double randreal(){ return (double)rand()/RAND_MAX; }
int n;
int w[15][15];
int x[1005], y[1005], wcnt;
int far[15], dep[15];
int dfs(int p){
    if(!far[p] or dep[p]) return 0;
    else{
        int sum=dfs(far[p]);
        dep[p]=dep[far[p]]+1;
        sum+=w[far[p]][p]*dep[p];
        return sum;
    }
}
inline int f(){
    ri i, sum=0;
    for(i=1; i<=n; i++) dep[i]=0;
    for(i=1; i<=n; i++) sum+=dfs(i);
    return sum;
}
inline int sa(){
    ri i, x, y, res, val, fary, ans, mode;
    rd t;
    t=T0;
    ans=res=f();
    while(t>T1){
        x=randint(1, n);
        do y=randint(1, n); while(w[x][y]==INF);
        if(dep[x]>dep[y]) swap(x, y);
        fary=far[y];
        far[y]=x;
        val=f();
        ans=min(ans, val);
        if(val<res or exp((res-val)/t)>randreal()) res=val;
        else{
            far[y]=fary;
            f();
        }
        t*=DELTA;
    }
    return ans;
}
int gf(int f[], int x){ return (x^f[x])?(f[x]=gf(f, f[x])):x; }
inline void random_spawn(int rt){
    int f[15], ord[1005], q[15], ql, qr, u, v;
    bool www[15][15];
    ri i;

    memset(www, 0, sizeof(www));

    for(i=1; i<=n; i++) f[i]=i, far[i]=0;
    for(i=1; i<=wcnt; i++) ord[i]=i;
    random_shuffle(ord+1, ord+1+wcnt);
    for(i=1; i<=wcnt; i++) if(gf(f, x[ord[i]])^gf(f, y[ord[i]])){
        f[gf(f, x[ord[i]])]=gf(f, y[ord[i]]);
        www[x[ord[i]]][y[ord[i]]]=www[y[ord[i]]][x[ord[i]]]=1;
    }
    q[ql=qr=1]=rt;
    while(ql<=qr){
        u=q[ql++];
        for(v=1; v<=n; v++) if(!far[v] and www[u][v] and v^rt){
            far[v]=u;
            q[++qr]=v;
        }
    }
}
inline int solve(){
    ri i, j, ans=INF;
    for(i=1; i<=n; i++){
        random_spawn(i);
        for(j=1; j<=SATIMES; j++) ans=min(ans, sa());
    }
    return ans;
}
int main(){
    memset(w, 0x3f, sizeof(w));

    ri i, j, m, u, v, f;
    #ifndef ONLINE_JUDGE
    freopen("2318.in", "r", stdin);
    freopen("2318.out", "w", stdout);
    #endif

    srand(173682999);

    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &f);
        w[v][u]=w[u][v]=min(w[u][v], f);
    }
    for(i=1; i<n; i++){
        for(j=i+1; j<=n; j++) if(w[i][j]^INF){
            ++wcnt;
            x[wcnt]=i;
            y[wcnt]=j;
        }
    }
    if(n>1) printf("%d\n", solve());
    else printf("0\n");
    return 0;
}
