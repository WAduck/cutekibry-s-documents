#include <cstdio>
#include <cstring>
#include <algorithm>
#define ri register int
//#define debug
using namespace std;
const int SCP=682*999/2, SPN=1<<30;
typedef long long int64;
inline void read(int &x){ register char ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void read(int &a, int &b){ read(a); read(b); }
inline void read(int &a, int &b, int &c){ read(a); read(b); read(c); }
inline void write(int64 x){ if(!x){ putchar('0'); return; } char buf[20]; register int top; for(top=0; x; x/=10) buf[++top]=(x%10)|48; while(top) putchar(buf[top--]); }
inline void writeln(int64 x){ write(x); putchar('\n'); }
struct Rabbit{ int col, p; };
Rabbit rabbit[SCP];
int rabbitpos[SCP];
bool rabbitcmp(Rabbit a, Rabbit b){ return (a.col^b.col)?(a.col<b.col):(a.p<b.p); }
int pos[SCP], cl[SCP], cr[SCP];
int main(){
	memset(cl, 0x3f, sizeof(cl));
	ri n, m, opt, l, r, x;
	read(n, m);
	for(ri i=1; i<=n; i++) read(rabbit[i].col), rabbit[i].p=i;
	sort(rabbit+1, rabbit+1+n, rabbitcmp);
	for(ri i=1; i<=n; i++){
		cl[rabbit[i].col]=min(cl[rabbit[i].col], i);
		cr[rabbit[i].col]=max(cr[rabbit[i].col], i);
		pos[rabbit[i].p]=i;
		rabbitpos[i]=rabbit[i].p;
	}
	for(ri i=1; i<=m; i++){
		read(opt);
		if(opt==1){
			read(l, r, x);
			if(!cr[x]) writeln(0);
			else{
				#ifdef debug
				putchar('#'); writeln(upper_bound(rabbitpos+cl[x], rabbitpos+cr[x]+1, r)-rabbitpos);
				putchar('#'); writeln(lower_bound(rabbitpos+cl[x], rabbitpos+cr[x]+1, l)-rabbitpos);
				#endif
				writeln(upper_bound(rabbitpos+cl[x], rabbitpos+cr[x]+1, r)-lower_bound(rabbitpos+cl[x], rabbitpos+cr[x]+1, l));
			}
		}
		else{
			read(x);
			if(rabbit[pos[x]].col^rabbit[pos[x+1]].col){
				rabbit[pos[x]].p++;
				rabbit[pos[x+1]].p--;
				rabbitpos[pos[x]]++;
				rabbitpos[pos[x+1]]--;
				swap(pos[x], pos[x+1]);
			}
		}
	}
}
