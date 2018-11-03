#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct choc{
	int p,t;
}t12[100001];
int c[100001];
int t3[100001];
bool cmp(choc x,choc y)
{return x.p<y.p;}
bool cmp2(int x,int y)
{return x>y;}
bool cmp3(int x,int y)
{return x<y;}
int main()
{
	//please input another sample
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	int n,i,j=0,b,w,p,t;
	int tmp=0,tmp2=0;
	int ans=0;
	scanf("%d%d%d",&n,&w,&b);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&t,&p);
		if(t==3)
		{
			t3[++j]=p;
			continue;
		}
		else
		{
			tmp2++;
			t12[tmp2].p=p,t12[tmp2].t=t;
		}
	}
	sort(t12+1,t12+tmp2+1,cmp);
	sort(t3+1,t3+j+1,cmp3);
	for(i=1;i<=tmp2;i++)
	{
		if(!w&&!b)
			break;
		if(t12[i].t==1&&w)
		{
			tmp++;
			w--;
			ans+=t12[i].p;
			c[tmp]=t12[i].p;
		}
		if(t12[i].t==2&&b)
		{
			tmp++;
			b--;
			ans+=t12[i].p;
			c[tmp]=t12[i].p;
		}
	}
//	int begin=1;
	sort(c+1,c+tmp+1,cmp2);
	for(i=1;i<=min(tmp,j);i++)
	{
		/*if(c[i]<=t3[i]&&!w&&!b)
		{
			printf("%lld",ans);
			return 0;
		}*/
		if(c[i]>t3[i])
		{
			ans+=t3[i];
			ans-=c[i];
			t3[i]=1e9+11;
		}
	}
	sort(t3+1,t3+j+1,cmp3);
	for(i=1;i<=w+b;i++)
		ans+=t3[i];
	printf("%d",ans);
	return 0;
}
/*
3 2 0
1 10000
3 1
3 100
*/

