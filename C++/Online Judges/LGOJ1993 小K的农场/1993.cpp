#include <cstdio>
#include <cstring>
#include <algorithm>
#define ri register int
#define rc register char
#define t1 template<class T1>
#define t2 template<class T1, class T2>
#define t3 template<class T1, class T2, class T3>
using namespace std;
const int SCP=682*999/6;

inline void read(int &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
t2 inline void read(T1 &a, T2 &b){ read(a); read(b); }
t3 inline void read(T1 &a, T2 &b, T3 &c){ read(a); read(b); read(c); }
t1 inline void write(T1 *s){ while(*s) putchar(*s++); }
t1 inline void writeln(T1 x){ write(x); putchar('\n'); }

int pre[SCP], to[SCP], wdis[SCP], head[SCP], cnt;
int dis[SCP];
int i, j, n, m, opt, x, y, z, u, v, w;
inline void addedge(int u, int v, int w){ pre[++cnt]=head[u]; head[u]=cnt; to[cnt]=v; wdis[cnt]=w; }
inline void addleq(int x, int y, int z){ addedge(y, x, z); } //x-y<=z
inline void addgeq(int x, int y, int z){ addleq(y, x, -z); } //x-y>=z
inline void addequal(int x, int y){ addleq(x, y, 0); addgeq(x, y, 0); } //x=y

int pq[SCP], pqtop, inqcnt;
bool inq[SCP];
bool pqcmp(int x, int y){ return dis[x]>dis[y]; }
inline int top(){ return pq[0]; }
inline void pop(){ pop_heap(pq, pq+pqtop--, pqcmp); }
inline void push(int x){ pq[pqtop++]=x; push_heap(pq, pq+pqtop, pqcmp); }
inline bool empty(){ return !pqtop; }
int main(){
	memset(dis, 0x3f, sizeof(dis));
	read(n);
	read(m);
	for(i=1; i<=m; i++){
		read(opt, x, y);
		if(opt==1) read(z), addgeq(x, y, z);
		else if(opt==2) read(z), addleq(x, y, z);
		else addequal(x, y);
	}
	for(i=1; i<=n; i++) if(dis[i]==0x3f3f3f3f){
		dis[i]=0;
		push(i);
		while(!empty()){
			u=top();
			inq[u]=0;
			pop();
			for(i=head[u]; i; i=pre[i]) if(dis[u]+(w=wdis[i])<dis[v=to[i]]){
				dis[v]=dis[u]+w;
				if(!inq[v]){
					if(++inqcnt>=SCP){
						writeln("No");
						return 0;
					}
					push(v);
					inq[v]=1;
				}
			}
		}
	}
	writeln("Yes");
	return 0;
}
/*
2 2
1 1 2 2
2 1 2 2
*/
