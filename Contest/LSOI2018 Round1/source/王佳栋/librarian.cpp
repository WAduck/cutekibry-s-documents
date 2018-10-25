#include<cstdio>//hai meiyou duipai de !!!!! jide 
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
char a[1000],b[1000];
ull book[1000],ren[1000];
const ull mod=19260817;
ull hashe(char s[])
{
	ull ans=1;
	ull len=strlen(s);
	for(int i=0;i<=len;i++)
	{
		ans+=((ans*(s[i]+12)*98674)%mod+88991522341)%mod;
	}
	return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,i,j,tmp,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",a);
		book[i]=hashe(a);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&tmp);
		getchar();
		scanf("%s",b);
		ren[i]=hashe(b);
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			if(ren[i]==book[j])
			{
				book[j]=-12315;
				printf("1\n");
				break;
			}
			if(j==n+1)
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
