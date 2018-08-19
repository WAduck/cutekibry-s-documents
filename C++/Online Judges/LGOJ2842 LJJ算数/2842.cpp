/*
a*a     g^x*g^x     g^(2x)
a^b     g^x*g^x*g^x*...*g^x     g^(xb)

a       ->  g^x
a^a     ->  g^x*g^x*g^x*g^x ->  g(ax)
a^a^a   ->  (a^a)^a ->  g^(xa)^a    ->  g^(xa)*g^(xa)*g^(xa)*...*g^(xa) ->  g^(aax)

a#b     ->  g^(x*a^(b-1))

bsgs:
                 g^x = a (mod p)
make m=ceil(sqrt(a)) and 0<=x<=m and 0<=y<m
            g^(xm+y) = a (mod p)
          g^xm * g^y = a (mod p)
                g^xm = a * inv(g^y) (mod p)
*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
// const int MOD=1e9+7, M=31623;
const int MOD=7, M=3;
int G;
int a[M+5];
int no[M+5];
int p[1005], pn;
int i, j, temp, bsgsx;
int64 x, y;
bool cmp(int x, int y){
    return a[x] < a[y];
}
inline int qpow(int b, int p, int mod){
    int res=1;
    while(p){
        if(p&1) res=(int64)res*b%mod;
        b=(int64)b*b%mod;
        p>>=1;
    }
    return res;
}
inline int getroot(){
    int i, j, temp;
    // 分解
    temp=MOD-1;
    for(i=2; i*i<=temp; i++) if(temp%i==0){
        p[++pn]=i;
        while(temp%i==0) temp/=i;
    }
    if(temp>>1) p[++pn]=temp;
    for(i=2; i<MOD; i++){
        for(j=1; j<=pn and qpow(i, (MOD-1)/p[j], MOD)!=1; j++);
        if(j>pn) return i;
    }
    return -1;
}
inline int bsgs(int x){
    int i, temp, inv, mpow, tno;

    temp=1;
    inv=qpow(G, MOD-2, MOD);
    for(i=0; i<M; i++){
        a[i]=temp;
        no[i]=i;
        temp=(int64)temp*inv%MOD;
    }
    sort(no, no+M, cmp);
    temp=qpow(x, MOD-2, MOD);
    mpow=qpow(G, M, MOD);
    for(i=0; i<=M; i++){
        a[M+1]=temp;
        tno=*lower_bound(no, no+M, M+1, cmp);
        if(a[tno]==temp) return tno+i*M;
        temp=(int64)temp*mpow%MOD;
    }
    return -1;
}
int main(){
    G=getroot();
    printf("%d\n", G);
    scanf("%lld %lld", &x, &y);
    bsgsx=bsgs(x);
    y%=MOD-1;
    printf("%d %d\n", bsgsx, qpow(x, y-1, MOD-1));
    printf("%d\n", qpow(G, (int64)bsgsx*qpow(x, y-1, MOD-1)%MOD-1, MOD)); // g^(x*a^(b-1))
    return 0;
}
