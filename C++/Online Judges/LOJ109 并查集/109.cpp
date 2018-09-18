#include <cstdio>
#define rc register char
#define ri register int
using namespace std;
const int BCP=682*999*8, MOD=998244353;
int far[BCP], size[BCP];
int gf(int x){ return (far[x]^x)?(far[x]=gf(far[x])):x; }
inline void read(int &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void swap(int &x, int &y){ ri temp=x; x=y; y=temp; }
int main(){
    ri n, m, i, opt, x, y, ans=0;
    read(n); read(m);
    for(i=1; i<=n; i++) far[i]=i, size[i]=1;
    for(i=1; i<=m; i++){
        read(opt); read(x); read(y);
        x=gf(x+1);
        y=gf(y+1);
        if(!opt){
            if(size[x]>size[y]) swap(x, y);
            far[x]=y;
        }
        else
            ans=((ans<<1)+!(x^y))%MOD;
    }
    printf("%d\n", ans);
    return 0;
}
