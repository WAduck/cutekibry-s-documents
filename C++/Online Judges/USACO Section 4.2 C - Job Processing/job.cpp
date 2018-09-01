/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: job
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
struct Node{
    int tot, cost;
    Node(){}
    Node(int _tot, int _cost){ tot=_tot; cost=_cost; }
    Node operator = (Node b){ tot=b.tot; cost=b.cost; return *this; }
    bool operator < (const Node &b) const{
        return tot+cost>b.tot+b.cost;
    }
};
const int SCP=682*999/600;
priority_queue<Node> pq;
Node tnode;
int a[SCP], atop;
int i, j, n, m1, m2, x, ans1, ans2;
int main(){
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    scanf("%d %d %d", &n, &m1, &m2);
    for(i=1; i<=m1; i++){
        scanf("%d", &x);
        pq.push(Node(0, x));
    }
    for(i=1; i<=n; i++){
        tnode=pq.top();
        pq.pop();
        a[i]=tnode.tot+tnode.cost;
        pq.push(Node(tnode.tot+tnode.cost, tnode.cost));
    }

    $ for(i=1; i<=n; i++) printf("%d ", a[i]);
    $ printf("\n");

    while(!pq.empty()) pq.pop();
    for(i=1; i<=m2; i++){
        scanf("%d", &x);
        pq.push(Node(0, x));
    }
    for(i=n; i; i--){
        tnode=pq.top();
        pq.pop();
        ans2=max(ans2, tnode.tot+tnode.cost+a[i]);
        pq.push(Node(tnode.tot+tnode.cost, tnode.cost));
    }
    printf("%d %d\n", a[n], ans2);
    return 0;
}
