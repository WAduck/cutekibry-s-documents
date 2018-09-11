#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int SCP=682*999/6;
struct Node{
    int p, dis;
    Node(){}
    Node(int _p, int _dis){ p=_p; dis=_dis; }
    Node operator = (Node b){ p=b.p; dis=b.dis; return *this; }
    bool operator < (const Node b) const{ return dis < b.dis; }
};
priority_queue<Node> pq;
int dis[SCP], price[SCP];
int pre[SCP], to[SCP], wdis[SCP], head[SCP], cnt;
int n, m, hp, i, j, k, u, v, w;
inline void addedge(int u, int v, int w){ pre[++cnt]=head[u]; head[u]=cnt; to[cnt]=v; wdis[cnt]=w; }
inline void add2edge(int u, int v, int w){ addedge(u, v, w); addedge(v, u, w); }
inline bool dijkstra(int lim){
    int i, u, v, w;
    Node tnode;
    memset(dis, 0x3f, sizeof(dis));
    dis[1]=0;
    pq.push(Node(1, 0));
    while(!pq.empty()){
        unode=pq.top();
        pq.pop();
        if(dis[u=unode.p]<unode.dis) continue;
        for(i=head[u]; i; i=pre[i]) if(price[v=to[i]]<=lim and dis[u]+(w=wdis[i])<dis[to[i]]){
            dis[v]=dis[u]+1;
            pq.push(Node(v, dis[v]));
        }
    }
    return dis[n]<=hp;
}
int main(){
}
