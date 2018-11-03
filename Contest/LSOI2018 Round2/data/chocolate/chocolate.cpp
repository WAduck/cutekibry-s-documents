#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
struct Node{
    int t, p;
    bool operator < (const Node _node) const{ return p<_node.p; }
};
Node a[100005];
int m, n1, n2, n3, i;
int64 ans;
int main(){
    #ifndef STDIO
    freopen("chocolate.in", "r", stdin);
    freopen("chocolate.out", "w", stdout);
    #endif

    scanf("%d %d %d", &m, &n1, &n2);
    for(i=1; i<=m; i++) scanf("%d %d", &a[i].t, &a[i].p);
    sort(a+1, a+1+m);
    for(i=1; i<=m; i++){
        if(a[i].t==1 and n1) n1--, ans+=a[i].p;
        else if(a[i].t==2 and n2) n2--, ans+=a[i].p;
        else if(a[i].t==3) n3++, ans+=a[i].p;
        if(!(n1+n2-n3)){
            printf("%lld\n", ans);
            return 0;
        }
    }
    printf("...");
    return 0;
}
