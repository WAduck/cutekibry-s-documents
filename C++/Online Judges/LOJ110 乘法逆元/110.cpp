#include <cstdio>
#define ll long long
using namespace std;
ll inv[3000005];
int main(){
    int i, n;
    ll p;
    
    scanf("%d %lld", &n, &p);
    inv[1]=1;
    printf("1\n");
    for(i=2; i<=n; i++)
        printf("%d\n", inv[i]=(p-p/i)*inv[p%i]%p);
    return 0;
}
