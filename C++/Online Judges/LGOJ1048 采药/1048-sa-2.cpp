#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define ri register int
#define rd register double
using namespace std;
const int INF=0x3f3f3f3f;
const double DELTA=0.985, T0=1500, T1=0.01;
const int SATIMES=10000;
bool chosen[105];
int w[105], v[105];
int n, m, vsum, wsum;
inline int randint(int l, int r){ return rand()%(r-l+1)+l; }
inline double randreal(){ return (double)rand()/RAND_MAX; }
inline int sa(){
    ri res=0, x;
    rd t;
    t=T0;
    while(t>T1){
        do x=randint(1, n); while(!chosen[x] and wsum+w[x]>m);
        if(!chosen[x]) res=max(res, vsum+v[x]);
        if(!chosen[x] or exp(-w[x]/t)>randreal()){
            vsum+=(chosen[x]?-1:1)*v[x];
            wsum+=(chosen[x]?-1:1)*w[x];
            chosen[x]=!chosen[x];
        }
        t*=DELTA;
    }
    return res;
}
inline int solve(){
    ri ans=0, i;
    for(i=1; i<=SATIMES; i++) ans=max(ans, sa());
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("1048.in", "r", stdin);
    freopen("1048.out", "w", stdout);
    #endif

    srand(173682999);
    ri i;

    scanf("%d %d", &m, &n);
    for(i=1; i<=n; i++) scanf("%d %d", &w[i], &v[i]);
    printf("%d\n", solve());
    return 0;
}
