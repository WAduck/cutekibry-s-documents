/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: butter
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/600;
int pre[SCP<<2], to[SCP<<2], wdis[SCP<<2], head[SCP], wcnt;
inline void addedge(int u, int v, int w){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; wdis[wcnt]=w; }
inline void add2edge(int u, int v, int w){ addedge(u, v, w); addedge(v, u, w); }
int n, m, p, i, j, u, v, w, sum, ans;
int a[SCP];
int dis[SCP][SCP];
struct Node{ int p, dis; Node(){} Node(int a, int b){ p=a; dis=b; } Node operator = (Node b){ p=b.p; dis=b.dis; return *this; } };
bool cmp(Node a, Node b){ return a.dis > b.dis; }
Node pq[SCP*20]; int pqtop;
inline Node top(){ return pq[0]; }
inline void pop(){ pop_heap(pq, pq+pqtop--, cmp); }
inline void push(Node x){ pq[pqtop++]=x; push_heap(pq, pq+pqtop, cmp); }
inline bool empty(){ return !pqtop; }
inline void dijkstra(int s){
    int i, u, v, w;
    Node unode;
    dis[s][s]=0;
    push(Node(s, 0));
    while(!empty()){
        unode=top();
        pop();
        if(dis[s][u=unode.p]<unode.dis) continue;
        u=unode.p;
        for(i=head[u]; i; i=pre[i]) if(dis[s][u]+(w=wdis[i])<dis[s][v=to[i]]){
            dis[s][v]=dis[s][u]+w;
            push(Node(v, dis[s][v]));
        }
    }
}

int main(){
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d %d %d", &p, &n, &m);
    for(i=1; i<=p; i++) scanf("%d", &a[i]);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &w);
        add2edge(u, v, w);
    }
    for(i=1; i<=n; i++) dijkstra(i);
    ans=0x3f3f3f3f;
    for(i=1; i<=n; i++){
        sum=0;
        for(j=1; j<=p; j++) sum+=dis[i][a[j]];
        ans=min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
