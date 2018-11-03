#include<cstdio>
using namespace std;
char a[100001],c;
int sum,i;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	for(i=1;i<=100001;++i)
	{
		c=getchar();
		a[i]=c;
	}
	for(i=1;i<=100001;++i)
	{
		if(a[i]=='f'&&a[i+1]=='r'&&a[i+2]=='e'&&a[i+3]=='o'&&a[i+4]=='p'&&a[i+5]=='e'&&a[i+6]=='n')
		{
			sum++;
			i+=6;
		}
	}
	printf("%d",sum);
	return 0;
}
