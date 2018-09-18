#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int64;
const int SCP=682*999/30;
struct Node{
    int p; int64 dis;
    Node(){}
    Node(int _p, int64 _dis){ p=_p; dis=_dis; }
    Node operator = (Node _node){ p=_node.p; dis=_node.dis; return *this; }
    bool operator < (const Node _node) const{ return dis > _node.dis; }
};
priority_queue<Node> pq;
int64 dis[SCP];
int pre[SCP], to[SCP], wdis[SCP], head[SCP], wcnt;
int n, m, s, t, i, u, v, w;
inline void addedge(int u, int v, int w){
    pre[++wcnt]=head[u];
    head[u]=wcnt;
    to[wcnt]=v;
    wdis[wcnt]=w;
}
inline int64 dijkstra(int s, int t){
    int i, u, v, w; Node unode;
    memset(dis, 0x3f, sizeof(dis));
    pq.push(Node(s, 0));
    dis[s]=0;
    while(!pq.empty()){
        unode=pq.top();
        pq.pop();
        if(unode.dis^dis[u=unode.p]) continue;
        for(i=head[u]; i; i=pre[i]) if(dis[u]+(w=wdis[i])<dis[v=to[i]]){
            dis[v]=dis[u]+w;
            pq.push(Node(v, dis[v]));
        }
    }
    return dis[t];
}
int main(){
    // freopen("119.in", "r", stdin);
    // freopen("119.out", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    printf("%lld\n", dijkstra(s, t));
    return 0;
}
