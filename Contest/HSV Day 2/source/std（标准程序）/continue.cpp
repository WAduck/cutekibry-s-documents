#include <cstdio>
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
int c[105], n, m, x, t, i, j, ans;
inline int lcm(int a, int b){
    x=a*b;
    while(b){
        t=a%b;
        a=b;
        b=t;
    }
    return x/a;
}
int main(){
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%d", &x);
        c[x]++;
    }
    for(i=1; i<=100; i++){
        ans=(ans+(int64)c[i]*(c[i]-1)/2%MOD*m)%MOD;
        for(j=1; j<i; j++)
            ans=(ans+(int64)c[i]*c[j]%MOD*(2*m-(int64)m*j/lcm(i, j)))%MOD;
    }
    printf("%d\n", ans);
    return 0;
}
