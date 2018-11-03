#include<cstdio>
#include<cmath>
using namespace std;
int n,a=40000000,b=40000000;
int i,m;
int main()
{
	freopen("cinnamoroll.in","r",stdin);
	freopen("cinnamoroll.out","w",stdout);
	scanf("%d%d",&n,&m);
	int sum=n,x=1;
	if(m==1)
	{
		scanf("%d",&a);
		for(int i=1;i<=n;++i)
		{
			if(i%a==0) sum--;
		}
	}
	if(m==2)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;++i)
		{
			if(i%a==0||i%b==0) sum--;
		}
	}
	if(sum==1||sum==2) printf("%d",sum);
	else
	{
		x=pow(x,sum-2)%1000000007;
	}
	printf("%d",x);
}
