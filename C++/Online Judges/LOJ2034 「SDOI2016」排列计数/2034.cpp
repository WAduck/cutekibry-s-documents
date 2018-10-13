#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int MOD=1e9+7;
int f[1000005], d[1000005];
char buff[20];
inline int qpow(int b, int p, int mod){
    int ans=1;
    while(p){
        if(p&1) ans=(int64)ans*b%mod;
        p>>=1;
        b=(int64)b*b%mod;
    }
    return ans;
}
inline void read(int &x){
    char ch;
    do ch=getchar(); while(ch<'0' or ch>'9');
    x=ch&15;
    ch=getchar();
    while(ch>='0' and ch<='9'){
        x=(x<<3)+(x<<1)+(ch&15);
        ch=getchar();
    }
}
inline void write(int x){
    if(!x){ putchar('0'); return; }
    int top=0;
    while(x){
        buff[++top]=x%10;
        x/=10;
    }
    while(top) putchar(buff[top--]|48);
}
inline void writeln(int x){
    write(x); putchar('\n');
}
inline int rev(int x){
    return qpow(x, MOD-2, MOD);
}
int main(){
    int i, j;
    int t, n, m, ans;

    read(t);
    f[1]=d[2]=1;
    for(i=2; i<=1000000; i++) f[i]=(int64)f[i-1]*i%MOD;
    for(i=3; i<=1000000; i++) d[i]=(int64)(i-1)*(d[i-1]+d[i-2])%MOD;
    while(t--){
        read(n); read(m);
        if(!m) ans=d[n];
        else if(n^m) ans=(int64)f[n]*rev(f[m])%MOD*rev(f[n-m])%MOD*d[n-m]%MOD;
        else ans=1;
        writeln(ans);
    }
    return 0;
}
