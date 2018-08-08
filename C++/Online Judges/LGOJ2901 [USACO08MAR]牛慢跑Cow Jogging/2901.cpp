#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ri register int
#define rc register char
#define tp template<class T>
using namespace std;
const int SCP=682*999/60, CP=682*999;

inline int read(int &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9'){ x=(x<<3)+(x<<1)+(ch&15); ch=getchar(); } }
inline void write(int x){ if(!x){ putchar('0'); return; } if(x<0){ putchar('-'); x=-x; } char buf[25]; ri top=0; while(x) buf[++top]=(x%10)|48, x/=10; while(top) putchar(buf[top--]); }
tp inline void writeln(T x){ write(x); putchar('\n'); }

struct Node{ int no, g, h; Node(){} Node(int a, int b, int c){ no=a; g=b; h=c; } Node operator = (Node b){ no=b.no; g=b.g; h=b.h; return *this; } };
struct Nodecmp{ bool operator ()(Node a, Node b){ return a.g+a.h>b.g+b.h; } };
priority_queue<Node, vector<Node>, Nodecmp> pq;

int pre[SCP<<1], to[SCP<<1], wdis[SCP<<1], head[SCP], _head[SCP], wcnt;
inline void addedge(int u, int v, int w){
	pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; wdis[wcnt]=w;
	pre[++wcnt]=_head[v]; _head[v]=wcnt; to[wcnt]=u; wdis[wcnt]=w;
}
int dis[SCP], cnt[SCP], res[SCP], i, j, n, m, k, u, v, w, x, y, s, t;
Node tnode;

inline void dijkstra(){
	memset(dis, 0x3f, sizeof(dis));
	dis[t]=0;
	pq.push(Node(t, 0, 0));
	while(!pq.empty()){
		tnode=pq.top();
		pq.pop();
		if(tnode.g^dis[tnode.no]) continue;
		u=tnode.no;
		for(i=_head[u]; i; i=pre[i]) if(dis[u]+(w=wdis[i])<dis[v=to[i]]){
			dis[v]=dis[u]+w;
			pq.push(Node(v, dis[v], 0));
		}
	}
}

inline void astar(){
	pq.push(Node(s, 0, dis[s]));
	while(!pq.empty()){
		tnode=pq.top();
		pq.pop();
		u=tnode.no;
		cnt[u]++;
		if(u==t) res[cnt[t]]=tnode.g;
		if(cnt[t]>k) return;
		for(i=head[u]; i; i=pre[i]) if(cnt[v=to[i]]<k)
			pq.push(Node(v, tnode.g+(w=wdis[i]), dis[v]));
	}
}

int main(){
	read(n); read(m); read(k);
	for(i=1; i<=m; i++){
		read(u); read(v); read(w);
		if(u<v) swap(u, v);
		addedge(u, v, w);
	}
	s=n;
	t=1;
	dijkstra();
	astar();
	for(i=1; i<=k; i++) writeln(res[i]?res[i]:-1);
	return 0;
}
