#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,q,i,c,a[101],b;
int main()
{
	string v;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=q;++i)
	{
		scanf("%d%d",&c,&b);
		int j=1;
		while(b!=a[j]&&j<=n)
		{
			j++;
			if(b==a[j]) break;
		}
		if(b==a[j])
		{
			printf("1\n");
			a[j]=-1;
		}
		else printf("0\n");
	}
}
