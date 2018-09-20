#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int from, to, v;
	bool operator < (const Node b){
		return v < b.v;
	}
};
Node w[500005];
int father[200005];
void set_init(){
	int i;
	for(i=1; i<=200000; i++)
		father[i]=i;
}
int set_get_father(int p){
	if(father[p]^p)
		return father[p]=set_get_father(father[p]);
	else
		return p;
}
bool set_find(int a, int b){
	return set_get_father(a)^set_get_father(b);
}
void set_union(int a, int b){
	father[set_get_father(a)]=set_get_father(b);
}
int main(){
	int i, j;
	int n, m;
	int p;
	int a, b, c;
	long long ans=0, t=0;

	set_init();

	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++)
		scanf("%d %d %d", &w[i].from, &w[i].to, &w[i].v);
	sort(w+1, w+1+m);
	for(i=1; i<=m and t<n; i++){
		if(set_find(w[i].from, w[i].to)){
			set_union(w[i].from, w[i].to);
			ans+=w[i].v;
			t++;
		}
	}
	printf("%lld", ans);
	return 0;
}
