#include <cstdio>
#include <algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int SCP=682*999/6, BCP=682*999*5;
int sum[BCP], lson[BCP], rson[BCP], cnt;
int far[SCP], root[SCP], size[SCP], pos[SCP];
int n, m, q;
int gf(int x){
	if(x^far[x]) return far[x]=gf(far[x]);
	else return x;
}
void prebuild(int &p, int l, int r, int x){
	sum[p=++cnt]=1;
	if(l==r) return;
	if(x<=mid) prebuild(lson[p], l, mid, x);
	else prebuild(rson[p], mid+1, r, x);
}
void mergetree(int &x, int y){
	if(!x){ x=y; return; }
	else if(!y) return;
	sum[x]+=sum[y];
	mergetree(lson[x], lson[y]);
	mergetree(rson[x], rson[y]);
}
int querytree(int p, int l, int r, int x){
	if(l==r) return l;
	else if(!p) return SCP-1;
	else if(x<=sum[lson[p]]) return querytree(lson[p], l, mid, x);
	else return querytree(rson[p], mid+1, r, x-sum[lson[p]]);
}
inline void merge(int x, int y){
	if(size[x]<size[y]) swap(x, y);
	mergetree(root[x], root[y]);
	size[x]+=size[y];
	far[y]=x;
}
int main(){
	int i, x, y;
	char opt;

	pos[SCP-1]=-1;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &x);
		pos[x]=far[i]=i, size[i]=1, prebuild(root[i], 1, n, x);
	}
	for(i=1; i<=m; i++){
		scanf("%d %d", &x, &y);
		merge(gf(x), gf(y));
	}
	scanf("%d", &q);
	for(i=1; i<=q; i++){
		scanf(" %c %d %d", &opt, &x, &y);
		if(opt=='B') merge(gf(x), gf(y));
		else printf("%d\n", pos[querytree(root[gf(x)], 1, n, y)]);
	}
}
