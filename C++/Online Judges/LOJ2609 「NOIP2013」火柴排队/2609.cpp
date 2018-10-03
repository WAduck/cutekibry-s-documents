#include <cstdio>
#include <algorithm>
#define ri register int
using namespace std;
typedef long long int64;
const int SCP=682*999/3;
const int MOD=99999997;
struct Node{
    int p, v;
    bool operator < (const Node _node) const{ return v < _node.v; }
};
Node a[SCP], b[SCP];
int x[SCP], c[SCP], n;
int i, j, k;
int ans;
// inline int id(int x){ return lower_bound(num+1, num+1+n, x)-num; }
inline int lowbit(int x){ return x&-x; }
inline void add(int p){ for(; p<=n; p+=lowbit(p)) c[p]++; }
inline int query(int p){ ri ans=0; for(; p; p-=lowbit(p)) ans+=c[p]; return ans; }
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i].v), a[i].p=i;
    for(i=1; i<=n; i++) scanf("%d", &b[i].v), b[i].p=i;
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    for(i=1; i<=n; i++) x[a[i].p]=b[i].p;
    for(i=1; i<=n; i++){
        add(x[i]);
        ans+=i-query(x[i]);
        if(ans>=MOD) ans-=MOD;
    }
    printf("%d\n", ans);
    return 0;
}
