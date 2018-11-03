#include<cstdio>
#include<cstring>
using namespace std;
//put things below
char a[200000];
int tot;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	for(int i = 1;;i++)
	{
		a[i] = getchar();
		if(a[i] == EOF)break;
		if(a[i] == 'n' && a[i-1] == 'e' && a[i-2] == 'p' && a[i-3] == 'o' && a[i-4] == 'e' && a[i-5] == 'r' && a[i-6] == 'f')tot+=1;
	}
	printf("%d",tot);
	return 0;
}
