#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll bgcd(ll a,ll b)
{
	if(a<b)swap(a,b);
	ll tmp=a; 
	while(1)
	{	
		if(tmp%b==0)
			break;
		tmp+=a;
	} 
	return tmp;
}
ll pow(ll b,ll p,ll k)
{
	ll ans=1;
	while(p)
	{
	
		if(p%2)
		{
			ans=ans*b%k;
		}
		b=b*b%k;
		p>>=1;
	}
	return ans%k;
}
int main()
{
//printf("%lld",bgcd(6,7));
	freopen("cinnamoroll.in","r",stdin);
	freopen("cinnamoroll.out","w",stdout);
	int n,m,tmp,a,b;
	scanf("%d%d",&n,&m);
	if(m==0);
	if(m==1)
	{
		scanf("%d",&tmp);
		n=n-n/tmp;
	}
	if(m==2)
	{
		scanf("%d%d",&a,&b);
		n=n-n/a;
		n=n-n/b;
		n=n+n/bgcd(a,b);
	}
	if(n==1)
	{
		printf("1");
		return 0;
	}
	if(n==2)
	{
		printf("1");
		return 0;
	}
	printf("%lld",pow(2,n-2,1000000007));
	return 0;
}
