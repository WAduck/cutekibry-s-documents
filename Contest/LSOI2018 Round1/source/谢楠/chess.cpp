#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[600001],x,i;
long long int sum,ans[600001];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(i=1;i<=q;++i)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;++j)
		{
			sum=0;
			for(int k=1;k<=n;++k)
			{
				sum+=(a[k]+j)*(a[k]+j);
			}
			ans[j]=sum/j;
		}
		sort(ans+1,ans+x+1);
		int v=1;
		while(ans[v]<=0) ++v;
		printf("%d\n",ans[v]);
	}
}
