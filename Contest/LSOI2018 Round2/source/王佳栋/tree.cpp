#include<cstdio>
#include<algorithm>
using namespace std;
char a[1000001];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n=0,i,cnt=0;
	a[cnt]=getchar();
	while(a[cnt]!=-1)
	{
		cnt++;
		a[cnt]=getchar();
	}
	for(i=0;i<cnt;i++)
	{
		if(a[i]=='f'&&a[i+1]=='r'&&a[i+2]=='e'&&a[i+3]=='o'&&a[i+4]=='p'&&a[i+5]=='e'&&a[i+6]=='n')
		{
			n++;
			i+=6;
		}
	}
	printf("%d",n);
	return 0;
}
