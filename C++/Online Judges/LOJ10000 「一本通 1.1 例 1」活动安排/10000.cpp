#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[2005], numn;
int l[1005], r[1005];
int pre[8005], to[8005], head[2005], wcnt;
int f[2005];
int n, m, i, j;
inline int id(int x){ return lower_bound(num+1, num+1+numn, x)-num; }
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d", &l[i], &r[i]);
        num[++numn]=l[i];
        num[++numn]=r[i];
    }
    sort(num+1, num+1+numn);
    for(i=1; i<=n; i++) l[i]=id(l[i]), r[i]=id(r[i]);
    for(i=1; i<=n; i++) addedge(r[i], l[i]);
    for(i=1; i<=numn; i++){
        f[i]=f[i-1];
        for(j=head[i]; j; j=pre[j]) f[i]=max(f[i], f[to[j]]+1);
    }
    printf("%d\n", f[numn]);
    return 0;
}
