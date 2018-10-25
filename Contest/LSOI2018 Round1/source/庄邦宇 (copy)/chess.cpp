#include<cstdio>
#include<algorithm>
using namespace std;
int n,q;
int a[600010];
int x[600010];
unsigned long long int fnl[600010];
int d0(int which)
{
	for(int h = 1;h <= n;h++)
	fnl[which]+=(a[h]+which)*(a[h]+which);
	fnl[which] /= which;
	return 0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int j = 1;j <= q;j++)
	scanf("%d",&x[j]);
	sort(x+1,x+1+q);
	for(int k = 1;k <= x[q];k++)
	d0(k);
	for(int l = 1;l <= q;l++)
	printf("%llu\n",fnl[x[l]]);
	return 0;
}
