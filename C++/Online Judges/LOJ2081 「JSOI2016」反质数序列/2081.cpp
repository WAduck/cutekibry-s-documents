#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/200;
int pre[SCP*SCP<<1], to[SCP*SCP<<1], head[SCP], cnt;
int col[SCP];
int q[SCP];
int a[SCP];
bool notp[200005];
int n, i, j, x, ans, sum;
bool is1;
inline void addedge(int u, int v){ pre[++cnt]=head[u]; head[u]=cnt; to[cnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
inline int fillcolor(int s){
    int i, u, v, ql, qr, colctr, ctr=0;
    col[s]=2;
    q[ql=qr=1]=s;
    ctr=colctr=1;
    while(ql<=qr){
        u=q[ql++];
        for(i=head[u]; i; i=pre[i]) if(!col[v=to[i]]){
            col[v]=col[u]^3;
            colctr+=col[v]>>1;
            ctr++;
            q[++qr]=v;
        }
    }
    return max(ctr-colctr, colctr);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("2081.in", "r", stdin);
    freopen("2081.out", "w", stdout);
    #endif

    for(i=2; i*i<=200000; i++) if(!notp[i]) for(j=i*i; j<=200000; j+=i) notp[j]=1;

    scanf("%d", &n);
    for(i=1, j=0; i<=n; i++){
        scanf("%d", &x);
        if(x==1) is1=1;
        else a[++j]=x;
    }
    n=j;
    for(i=1; i<=n; i++) for(j=1; j<=n; j++) if(!notp[a[i]+a[j]]) add2edge(i, j);
    for(i=1; i<=n; i++) if(!col[i]) sum+=fillcolor(i);
    ans=sum;

    if(is1){
        memset(col, 0, sizeof(col));
        sum=1;
        for(i=1; i<=n; i++) if(!notp[a[i]+1]) col[i]=1;
        for(i=1; i<=n; i++) if(!col[i]) sum+=fillcolor(i);
        ans=max(ans, sum);
    }

    printf("%d\n", ans);
    return 0;
}
