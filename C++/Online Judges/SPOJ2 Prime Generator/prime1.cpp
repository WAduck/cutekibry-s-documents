#include <cstdio>
using namespace std;
inline bool judge(int x){
    int i;
    for(i=2; i*i<=x; i++) if(!(x%i)) return false;
    return x>>1;
}
int T;
int l, r, i;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &l, &r);
        for(i=l; i<=r; i++) if(judge(i)) printf("%d\n", i);
        putchar('\n');
    }
    return 0;
}
