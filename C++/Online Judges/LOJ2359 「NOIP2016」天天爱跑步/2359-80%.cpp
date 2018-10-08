// 80%
#include <cstdio>
#define ri register int
using namespace std;
const int SCP=682*999/6;

// Core
int W[SCP], S[SCP], T[SCP];
int far[SCP], dep[SCP];
int pre[SCP<<1], to[SCP<<1], head[SCP], ans[SCP], wcnt;
int n, m;
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
void dfs(int u){
    int i, v;
    for(i=head[p]; i; i=pre[i]) if(!dep[v=to[i]]){
        far[v]=u;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
inline void input(){
    ri i, u, v;
    for(i=1; i<n; i++) scanf("%d %d", &u, &v), add2edge(u, v);
    for(i=1; i<=n; i++) scanf("%d", &W[i]);
    for(i=1; i<=m; i++) scanf("%d %d", &S[i], &T[i]);
    dep[1]=1;
    dfs(1);
}
inline void output(){
    ri i;
    for(i=1; i<=n; i++) printf("%d\n", ans[i]);
}

// Subtask 1~4: Si=Ti or Wj=0
inline void solve_easy(){
    ri i;
    for(i=1; i<=m; i++) if(!W[S[i]]) ans[S[i]]++;
}

// Subtask 5: Brust
// inline void solve_brust(){
//     ri i, j, s, t;
//     for(i=1; i<=m; i++){
//         s=S[i];
//         t=T[i];
//         if(dep[s])
//     }
// }

// Subtask 6~8: Link
struct Node{
    int l, r;
    Node(int _l=0, int _r=0){ l=_l; r=_r; }
    Node operator = (Node b){ l=b.l; r=b.r; return *this; }
};
bool acmp(Node a, Node b){ return (a.l^b.l)?(a.l<b.l):(a.r<b.r); }
bool bcmp(Node a, Node b){ return (a.l^b.l)?(a.l>b.l):(a.r>b.r); }
Node aska[SCP], askb[SCP]; int acnt, bcnt;
int buc[SCP];
inline void solve_link(){
    ri i, ql, qr;
    for(i=1; i<=m; i++){
        if(S[i]<=T[i]) aska[++acnt]=Node(S[i], T[i]);
        else askb[++bcnt]=Node(S[i], T[i]);
    }
    sort(aska+1, aska+1+acnt, acmp);
    sort(askb+1, askb+1+bcnt, bcmp);
    ql=1;
    qr=0;
    for(i=1; i<=n; i++){
        while(qr<m and aska[qr+1].l==i) buc[aska[++qr].l]++;
        while(ql<=qr and aska[ql].r<i) buc[aska[ql++].l]--;
        if(i-W[i]>=1) ans[i]+=buc[i-W[i]];
    }
    ql=1;
    qr=0;
    for(i=n; i; i--){
        while(qr<m and askb[qr+1].l==i) buc[aska[++qr].l]++;
        while(ql<=qr and askb[ql].r>i) buc[aska[ql++].l]--;
        if(i+W[i]<=n) ans[i]+=buc[i+W[i]];
    }
}

// Subtask 9~12: Si=1
void dfssi(int u){
    int i, v;
    for(i=head[u]; i; i=pre[i]) if(far[v=to[i]]==u){
        dfssi(v);
        ans[v]+=ans[u];
    }
}
inline void solve_si(){
    ri i;
    for(i=1; i<=m; i++) ans[T[i]]++;
    dfssi(1);
    for(i=1; i<=n; i++) if(W[i]!=dep[i]-1) ans[i]=0;
}

// Subtask 13~16: Ti=1
