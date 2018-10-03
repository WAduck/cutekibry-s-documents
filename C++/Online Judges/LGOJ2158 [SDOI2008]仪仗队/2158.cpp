#include <cstdio>
using namespace std;
int phi(int x){
    // printf("# phi(%d)=", x);
    int res=x, i;
    for(i=2; i*i<=x; i++) if(!(x%i)){
        res=res/i*(i-1);
        while(!(x%i)) x/=i;
    }
    if(x>>1) res=res/x*(x-1);
    // printf("%d\n", res);
    return res;
}
int i, n, ans;
int main(){
    scanf("%d", &n);
    ans=(n-1)?3:0;
    for(i=2; i<n; i++) ans+=phi(i)<<1;
    printf("%d\n", ans);
    return 0;
}
/*
4       .   .
3       .       .
2   .   .   .
1   o   .
    1   2   3   4

3       .   .
2       .       .
1   .   .   .   .
0   o   .
    0   1   2   3
*/
