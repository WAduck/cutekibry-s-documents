#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,i,tot,tmp,tmp2;
double zuoye,xiaoce;
int a[3000001],b[101];
double ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int my=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		tot+=tmp;
	}
	zuoye=(double(1.0*tot/n))*0.2;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&tmp);
		b[tmp]++;
	}
	for(i=100;i>=0;i--)
	{
		if(b[i]==1&&!my)	//b[i]&&!my
		{
			tmp2=i;
			break;
		}
		if(b[i])
			my=0;
	}
	int x;
	scanf("%d",&x);
	ans=zuoye+double(1.0*tmp2*0.3)+double(1.0*x*0.5);
	tmp=int(ans);
	if(ans-double(1.0*tmp)>=0.5)
	{
		printf("%d",tmp+1);
		return 0;
	}
	printf("%d",tmp);
	return 0;
}
