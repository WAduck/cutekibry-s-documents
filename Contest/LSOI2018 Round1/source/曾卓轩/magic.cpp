#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=405;
const int p=1e9+7;

int n;
int vis[maxn];

int dfs(int step){
	if(step>n)
		return 0;
	int ans=0;
	for(int i=step+1;i<=n;i++)
		if(!vis[i]){
			vis[i]=vis[i*i]=true;
			ans=(ans+dfs(i))%p;
			vis[i]=vis[i*i]=false;
		}
//	for(int i=1;i<=n;i++)
//		if(vis[i])
//			printf("%d ",i);
//	printf("\n");
	return (ans+1)%p;
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	int ans=dfs(0)%p;
	printf("%d\n",ans);
	return 0;
}
