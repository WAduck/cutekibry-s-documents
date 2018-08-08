#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int64;
inline void read(int &x){ register char ch; register bool neg=0; do ch=getchar(); while((ch<'0' or ch>'9') and ch^'-'); if(!(ch^'-')) neg=1, ch=getchar(); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); if(neg) x=-x; }
inline void read(int &a, int &b){ read(a); read(b); }
inline void read(int &a, int &b, int &c){ read(a); read(b); read(c); }
inline void write(int64 x){ if(!x){ putchar('0'); return; } if(x<0) putchar('-'), x=-x; char buf[20]; register int top; for(top=0; x; x/=10) buf[++top]=(x%10)|48; while(top) putchar(buf[top--]); }
inline void writeln(int64 x){ write(x); putchar('\n'); }
using namespace std;
const int SCP=682*999/3, BCP=682*999*2;
int pre[SCP<<3], to[SCP<<3], wdis[SCP<<3], head[SCP], cnt;
int q[SCP], qtop;
int dis[SCP];
bool vis[SCP];
int i, l, r, u, v, w, n, m, inqcnt;
inline void addedge(int u, int v, int w){
	pre[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	wdis[cnt]=w;
}
inline void addleq(int a, int b, int c){ addedge(b, a, c); }  //a-b<=c
inline void addgeq(int a, int b, int c){ addleq(b, a, -c); } //a-b>=c	->	b-a<=-c
bool cmp(int a, int b){ return dis[a]>dis[b]; }
inline int top(){ return q[0]; }
inline int push(int x){ q[qtop++]=x; push_heap(q, q+qtop, cmp); }
inline void pop(){ pop_heap(q, q+qtop--, cmp); }
inline bool isempty(){ return !qtop; }
int main(){
	memset(dis, 0x3f, sizeof(dis));
	read(n, m);
	for(i=1; i<=n; i++) addgeq(i, i-1, 0), addleq(i, i-1, 1); //sum[i]-sum[i-1]>=0  sum[i]-sum[i-1]<=1
	for(i=1; i<=m; i++){
		read(l, r);
		addgeq(r, l-1, 1); addleq(r, l-1, 1); //sum[r]-sum[l-1]>=1  sum[r]-sum[l-1]<=1
	}
	dis[0]=0;
	push(0);
	while(!isempty()){
		u=top();
		vis[u]=0;
		pop();
		for(i=head[u]; i; i=pre[i]){
			v=to[i];
			if(dis[u]+(w=wdis[i])<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					if(++inqcnt>=BCP){
						writeln(-1);
						return 0;
					}
					vis[v]=1;
					push(v);
				}
			}
		}
	}
	writeln(dis[n]);
	return 0;
}
/*
5 3
1 2
4 5
1 5
*/
