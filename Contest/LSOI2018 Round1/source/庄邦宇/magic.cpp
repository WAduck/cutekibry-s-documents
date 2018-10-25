#include<cstdio>
using namespace std;
int n;
long long int tot;
int how_much;
int a[401];
bool used[401];
int chk(int last)
{
	if(last == n+1)return 0;
	for(int j = last;j <= n;j++)
{
	if(last == 1 && j == 2)return 0;
	if(used[j] != 1){tot+=1;tot%=1000000007;used[j] = true;a[last] = j;if(j*j<=n)used[j*j] = true;chk(last+1);used[j] = 0;a[last] = 0;used[j*j] = false;}
}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	if(n == 1){printf("2\n");return 0;}
	tot = n+1;
	chk(1);
	printf("%d\n",tot);
	return 0;
}
