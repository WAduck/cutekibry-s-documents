#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[1000001],ans[1000001],tot,b[1000001];
int n,q,x; 
inline ll get(int x)
{
	ll fh=0;
	memset(b,0,sizeof(b));
	if(ans[x])return ans[x];
	for(int j=1;j<=n;j++)
	{
		b[j]=a[j]+x;
	}
	for(int j=1;j<=n;j++)
		fh+=b[j]*b[j];
	return ans[fh]=fh/x;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		tot+=a[i];
	}
	ll len=tot/n;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&x);
		if(x>=len)
		{
			printf("%d\n",get(len));
			continue;
		}
		printf("%d\n",get(x));
	}
	return 0;
}
