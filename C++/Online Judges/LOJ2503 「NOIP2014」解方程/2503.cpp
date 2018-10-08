#include <cstdio>
#define ri register int
#define rc register char
#define rb register bool
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
int a[105], b[1000005], cnt;
int i, j, n, m;
inline void read(int &x){
    rc ch;
    rb neg=false;
    do ch=getchar(); while(ch^'-' and (ch<'0' or ch>'9'));
    if(ch=='-') neg=true, ch=getchar();
    x=0;
    while(ch>='0' and ch<='9') x=((int64)x*10+(ch&15))%MOD, ch=getchar();
    if(neg and x) x=MOD-x;
}
inline int cal(int x){
    ri i, v=a[n];
    for(i=n-1; i+1; i--) v=((int64)v*x+a[i])%MOD;
    return v;
}
int main(){
    ri i;
    read(n); read(m);
    for(i=0; i<=n; i++) read(a[i]);
    // for(i=1; i<=m; i++) printf("%d\n", cal(i));
    for(i=1; i<=m; i++) if(!cal(i)) b[++cnt]=i;
    printf("%d\n", cnt);
    for(i=1; i<=cnt; i++) printf("%d\n", b[i]);
    return 0;
}
