#include <cstdio>
#include <algorithm>
#define ri register int
using namespace std;
typedef long long int64;
const int SCP=682*999/12;
int d[SCP], mu[SCP], p[SCP], pn;
int64 dsum[SCP]; int musum[SCP];
bool notp[SCP];
inline void getmu(int n){
    ri i, j;
    d[1]=1;
    mu[1]=1;
    for(i=2; i<=n; i++){
        if(!notp[i]){
            mu[i]=-1;
            p[++pn]=i;
        }
        for(j=1; i*p[j]<=n and j<=pn; j++){
            notp[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i];
            else{
                mu[i*p[j]]=0;
                break;
            }
        }
        for(j=1; j*j<i; j++) if(!(i%j)) d[i]+=2;
        if(j*j==i) d[i]++;
    }
    for(i=1; i<=n; i++) dsum[i]=dsum[i-1]+d[i], musum[i]=musum[i-1]+mu[i];
}
int main(){
    ri i, j, T, n, m;
    int64 ans;

    getmu(50000);
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        ans=0;
        if(n>m) swap(n, m);
        for(i=1; i<=n; i=j+1){
            j=min(n, min(n/(n/i), m/(m/i)));
            // printf("# %d %d musum=%d dsum[n/i]=%d dsum[m/i]=%d\n", i, j, musum[j]-musum[i-1], dsum[n/i], dsum[m/i]);
            ans+=(int64)(musum[j]-musum[i-1])*dsum[n/i]*dsum[m/i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
