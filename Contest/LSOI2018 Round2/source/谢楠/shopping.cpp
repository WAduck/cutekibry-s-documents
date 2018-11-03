#include<cstdio>
using namespace std;
int n,a,b,c,i,j,m,p,v,sum=0,sum1=0,sum2=0,f[10000]={0,0};
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&f[i]);
	}
	for(i=1;i<=n;++i)
	{
		sum+=f[i];
		for(j=1;j<=m;++j)
		{
			scanf("%d%d",&p,&v);
			sum2+=v;
			sum1+=p;
			if(sum1>a)
			{
				sum1-=p;
				sum2-=v;
				continue;
			}
			else if(sum1<=a&&sum2>=b)
			{
				printf("%d",sum);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
