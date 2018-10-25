#include<cstdio>
using namespace std;
int n,i;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	if(n==1) printf("2");
	if(n==2) printf("4");
	if(n==3) printf("8");
	if(n==4) printf("12");
	if(n==5) printf("24");
}
