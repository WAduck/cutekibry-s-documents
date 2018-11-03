#include <cstdio>
#include <algorithm>
using namespace std;
const int SCP=682*999/6, SPN=100001;
int a[SCP];
int n, i, j, min0, min1, ans;
struct Node{
    int p, v;
    Node(int _p=0, int _v=0){ p=_p; v=_v; }
    Node operator = (Node _node){ p=_node.p; v=_node.v; return *this; }
    bool operator < (const Node _node) const{ return v<_node.v; }
} sum[2][SCP];
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    for(i=1; i<=SPN; i++) sum[0][i]=sum[1][i]=Node(i, n>>1);
    for(i=1; i<=n; i++) sum[i&1][a[i]].v--;
    sort(sum[0]+1, sum[0]+SPN+1);
    sort(sum[1]+1, sum[1]+SPN+1);
    ans=n;
    for(i=1; i<=5; i++){
        for(j=1; j<=5; j++) if(sum[0][i].p^sum[1][j].p){
            ans=min(ans, sum[0][i].v+sum[1][j].v);
        }
    }
    printf("%d\n", ans);
    return 0;
}
