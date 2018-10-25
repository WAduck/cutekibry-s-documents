#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,ans,vis[4010],a[4001],tmp;
void dfs(int pos)
{
	a[++tmp]=pos;
	int i;
	ans++;
	vis[pos*pos]=1;	
	vis[pos]=1;
	for(i=pos+1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);

		}
	}
	vis[pos*pos]=0;
	vis[pos]=0;
	a[tmp]=0;
	tmp--;
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i);
	}
	printf("%d",ans+1);
}
