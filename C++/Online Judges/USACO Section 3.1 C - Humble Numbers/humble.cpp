/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: humble
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define $ if(0)
using namespace std;
const int SCP=682*999/6;
int LIM;
typedef long long int64;
int64 pq[SCP], a[SCP], c[SCP], xx[SCP], pqtop, an;
inline int64 top(){ return pq[0]; }
inline void pop(){ pop_heap(pq, pq+pqtop--); }
inline void push(int64 x){ pq[pqtop++]=x; push_heap(pq, pq+pqtop); }
inline bool empty(){ return !pqtop; }
int i, j, n, m;
int64 x, y, z;
int main(){
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    scanf("%d %d", &n, &m); m++;
    LIM=0x7fffffff;
    if(n>=70) LIM=500000;
    for(i=1; i<=n; i++) scanf("%lld", &xx[i]);
    for(i=1, j=n; i<j; i++, j--) swap(xx[i], xx[j]);
    // for(i=1; i<=n; i++) printf("%d ", xx[i]);
    push(1);
    for(i=1; i<=n; i++){
        x=xx[i];
        memcpy(c, pq, sizeof(pq));
        an=0;
        while(!empty()){
            a[an++]=top();
            pop();
        }
        pqtop=an;
        memcpy(pq, c, sizeof(c));
        $ printf("# %d %d\n", pqtop, top());
        scanf("%lld", &x);
        z=x;
        while(z<=LIM){
            for(j=an-1; j+1 and z*a[j]<=LIM; j--){
                if(pqtop==m and z*a[j]>=top()) break;
                if(pqtop==m) pop();
                push(z*a[j]);
                $ printf("push(%d)\n", z*a[j]);
            }
            z*=x;
        }
        $ for(j=0; j<pqtop; j++) printf("%d ", pq[j]);
        $ putchar('\n');
    }
    printf("%d\n", top());
    return 0;
}
