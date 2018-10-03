#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/6, BCP=682*999*30;
int head[SCP], pre[SCP<<2], to[SCP<<2], wdis[SCP<<2], cnt;
int rhead[SCP], rpre[SCP<<2], rto[SCP<<2], rdis[SCP<<2], rcnt;
int dis[SCP];
int f[SCP][51];
bool vis[SCP][51], dfsvis[SCP][51];
int q[BCP], ql, qr;
int n, m, k, mod;
bool err;
inline void addedge(int x, int y, int z){
	pre[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
	wdis[cnt]=z;
}
inline void raddedge(int x, int y, int z){
	rpre[++rcnt]=rhead[x];
	rhead[x]=rcnt;
	rto[rcnt]=y;
	rdis[rcnt]=z;
}

void spfa(){
	int i, u, v, w;
	q[ql=qr=1]=1;
	dis[1]=0;
	while(ql<=qr){
		if(dis[q[ql]]<=dis[q[qr]]) u=q[ql++];
		else u=q[qr--];
		vis[u][0]=false;
		for(i=head[u]; i; i=pre[i]) if(dis[v=to[i]]>=dis[u]+(w=wdis[i])){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v][0]){
					q[++qr]=v;
					vis[v][0]=true;
				}
			}
		}
	}
}
int dfs(int u, int p){
	int i;
	if(p<0) return 0;
	if(vis[u][p] or err){ err=true; return 0; }
	if(dfsvis[u][p]) return f[u][p];
	vis[u][p]=dfsvis[u][p]=true;
	for(i=rhead[u]; i; i=rpre[i])
		f[u][p]=(f[u][p]+dfs(rto[i], p-(dis[rto[i]]+rdis[i]-dis[u])))%mod;
	vis[u][p]=false;
	if(u==1 and !p) f[u][p]=bool(mod);
	return f[u][p];
}
int main(){
	int i, u, v, w, t, ans=0;

	scanf("%d", &t);
	while(t--){
		memset(dis, 0x3f, sizeof(dis));
		memset(head, 0, sizeof(head));
		memset(rhead, 0, sizeof(rhead));
		memset(f, 0, sizeof(f));
		memset(dfsvis, 0, sizeof(dfsvis));
		rcnt=cnt=0;
		ans=0;
		err=0;

		scanf("%d %d %d %d", &n, &m, &k, &mod);
		for(i=1; i<=m; i++){
			scanf("%d %d %d", &u, &v, &w);
			addedge(u, v, w);
			raddedge(v, u, w);
		}
		spfa();
		for(i=0; i<=k; i++) ans=(ans+dfs(n, i))%mod;
		if(err) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
/*
5
5 10 0 624775377
1 2 1
2 5 2
2 4 1
5 4 2
4 2 1
4 5 2
2 3 1
3 2 1
1 3 2
3 5 1
5 10 0 511184987
1 4 1
4 5 1
3 4 2
2 3 1
2 1 1
2 5 2
3 1 1
1 3 2
5 1 2
4 1 2
5 10 0 595078320
1 2 1
2 5 1
2 1 2
5 2 1
2 3 1
3 5 1
1 5 2
4 1 1
3 1 2
4 2 1
5 10 0 128304001
1 3 1
3 5 1
2 5 2
1 5 2
4 5 1
1 4 1
3 1 1
2 3 1
2 1 1
5 2 1
5 10 0 796750861
1 4 1
4 5 2
2 5 1
4 3 2
1 3 1
2 1 2
5 4 2
3 4 2
1 5 1
5 1 2

*/
