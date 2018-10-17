#include <cstdio>
#include <algorithm>
#define ri register int
using namespace std;
typedef long long int64;
const int SCP=682*999/12;
int musum[SCP]; bool notprime[SCP];
int prime[SCP], pn;
inline void getmu(int n){
    ri i, j;
    musum[1]=1;
    for(i=2; i<=n; i++){
        if(!notprime[i]){
            prime[++pn]=i;
            musum[i]=-1;
        }
        for(j=1; i*prime[j]<=n and j<=pn; j++){
            notprime[i*prime[j]]=1;
            if(i%prime[j]) musum[i*prime[j]]=-musum[i];
            else{
                musum[i*prime[j]]=0;
                break;
            }
        }
    }
    for(i=2; i<=n; i++) musum[i]+=musum[i-1];
}
inline int64 f(int n, int m, int k){
    ri i, j;
    int64 ans=0;
    if(n>m) swap(n, m);
    for(i=1; i<=n/k; i=j+1){
        j=min(n/k, min(n/(n/(i*k)), m/(m/(i*k)))/k);
        // printf("%d %d\n", i, j);
        ans+=(int64)(musum[j]-musum[i-1])*(n/(i*k))*(m/(i*k));
    }
    // printf("f(%d, %d, %d)=%d\n", n, m, k, ans);
    return ans;
}
int main(){
    ri i, j, T, a, b, c, d, k;
    getmu(50000);
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        printf("%lld\n", f(b, d, k)-f(a-1, d, k)-f(b, c-1, k)+f(a-1, c-1, k));
    }
    return 0;
}
