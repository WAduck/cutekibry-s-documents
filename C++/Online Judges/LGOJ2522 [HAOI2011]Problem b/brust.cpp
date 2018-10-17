#include <cstdio>
using namespace std;
int gcd(int x, int y){ return y?gcd(y, x%y):x; }
int main(){
    int T, i, j, a, b, c, d, k, ans;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        ans=0;
        for(i=a; i<=b; i++) for(j=c; j<=d; j++) ans+=gcd(i, j)==k;
        printf("%d\n", ans);
    }
    return 0;
}
