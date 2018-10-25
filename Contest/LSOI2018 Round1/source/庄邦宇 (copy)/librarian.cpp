#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
char book[110][110];
char read[110];
bool used[110];
int how_many;
int judge(int which)
{
	for(int l = 0;l < strlen(book[which]);l++)
	if(read[l] != book[which][l])return false;
	return true;
}
int chk()
{
	for(int h = 1;h <= n;h++)
	if(used[h] != true && judge(h)){printf("1\n");used[h] = true;return 0;}
	printf("0\n");
	return 0;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	char bin;
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++)
	{
	scanf("%c",&bin);
	scanf("%s",book[i]);
	}
	for(int j = 1;j <= q;j++)
	{
	scanf("%d",&how_many);
	scanf("%s",read);
	chk();
}
return 0;
}
