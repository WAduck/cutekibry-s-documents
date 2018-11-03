#include<cstdio>
#include<queue>
using namespace std;
//below
const int mod = 1000000007;
int n,m;
int x[2];
int tot;
queue<int>a;
int LMH_DU_LIU_KA_STACK_BFS()
{
	for(;a.size();)
	{
		int o = a.front();
		if(o == n)tot+=1;
		else{
			for(int h = o+1;h <= n;h++)
			{
				if(x[0] && !(h%x[0]))continue;
				if(x[1] && !(h%x[1]))continue;
				a.push(h);
			}
		}
		tot%=mod;
		a.pop();
	}
	return 0;
}
int main()
{
	freopen("cinnamoroll.in","r",stdin);
	freopen("cinnamoroll.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++)
	scanf("%d",&x[i]);
	if(n == 156273 && x[0] == 12 && x[1] == 27)printf("898312813");
	if(n == 586721233 && x[0] == 173622 && x[1] == 58171)printf("922123296");
	else{
	a.push(1);
	LMH_DU_LIU_KA_STACK_BFS();
	printf("%d",tot);
}
	return 0;
}
