#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct article{
	int from,v,w,dis;
}array[10001];
int f[10001];
int n,a,b,d[1001];
int w[1001],v[1001],cnt;
inline int dp(int l,int r)
{
	int cnt2=0,i,j;
	memset(f,0,sizeof(f));
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	for(i=1;i<=cnt;i++)
	{
		if(array[i].from>=l&&array[i].from<=r)
		{
			w[++cnt2]=array[i].w;
			v[cnt2]=array[i].v;
		}
	}
	for(i=1;i<=cnt2;i++)
		for(j=a;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	return f[a];
}
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int i,j,tmp,ans=1e9;
	scanf("%d%d%d",&n,&a,&b);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&tmp);
		d[i]=d[i-1]+tmp;
	}
	for(i=1;i<=n;i++)	
	{
		scanf("%d",&tmp);
		for(j=1;j<=tmp;j++)
		{
			cnt++;
			scanf("%d%d",&array[cnt].w,&array[cnt].v);
			array[cnt].from=i;
		}
	}
//	printf("%d",dp(1,1));
/*	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			printf("dp %d %d=%d  ",i,j,dp(i,j));*/
	int lbound=1,rbound=1;
	while(rbound<=n)
	{
		if(dp(lbound,rbound)>=b)
		{
			ans=min(ans,d[rbound]-d[lbound]);
			lbound++;
			rbound=lbound;
		}
		else
			rbound++;
	}
	if(ans!=1e9)
	printf("%d",ans);
	else
		printf("-1");
	return 0;
}
