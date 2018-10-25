#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,i,j;
float a,c,d,x,sum1=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d",&n,&m);
	int b[m];
	for(i=1;i<=n;++i)
	{
		scanf("%f",&a);
		sum1+=a;
	}
	for(i=0;i<m;++i)
	{
		scanf("%d",&b[i]);
	}
	sort(b,b+m);
	d=b[m-2];
	scanf("%f",&c);
	printf("%0.0f",sum1/n*0.2+d*0.3+c*0.5);
}
