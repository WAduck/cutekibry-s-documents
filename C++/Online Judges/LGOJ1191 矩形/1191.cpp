#include <cstdio>
#include <algorithm>
#define y1 y111111
#define ri register int
#define rc register char
#define t1 template<class T1>
#define t2 template<class T1, class T2>
#define t3 template<class T1, class T2, class T3>
using namespace std;
typedef long long int64;
const int SCP=682*999/3000;

t1 inline void read(T1 &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void read(char &ch){ do ch=getchar(); while(ch<=32); }
t2 inline void read(T1 &a, T2 &b){ read(a); read(b); }
t3 inline void read(T1 &a, T2 &b, T3 &c){ read(a); read(b); read(c); }
t1 inline void write(T1 x){ if(!x){ putchar('0'); return; } if(x<0) putchar('-'), x=-x; char buf[25]; ri top=0; while(x) buf[++top]=(x%10)|48, x/=10; while(top) putchar(buf[top--]); }
t1 inline void write(T1 *s){ while(*s) putchar(*s++); }
t1 inline void writeln(T1 x){ write(x); putchar('\n'); }

int sum[SCP][SCP];
int i, j, x1, y1, x2, y2, n; char ch;
int64 ans;
int main(){
    read(n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            read(ch);
            sum[i][j]=(ch=='B')+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(x1=1; x1<=n; x1++){
        for(x2=x1; x2<=n; x2++){
            for(y1=y2=1; y1<=n; y1++){
                while(!(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]) and y2<=n) y2++;
                ans+=y2-y1;
            }
        }
    }
    writeln(ans);
    return 0;
}
