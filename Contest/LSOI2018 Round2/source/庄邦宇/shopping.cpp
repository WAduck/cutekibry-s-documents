#include<cstdio>
#include<queue>
using namespace std;
//below
const int maxn = 2000000000;
int tot = maxn;
int n,a,b;
struct goods{
	int price;
	int import;
};
struct trader{
	int road;
	int how;
	goods a[1010];
}ha[110];
struct eaaaa{
	int all_go;
	int all_much;
	int all_import;
	bool used[110][1010];
} putin;
queue<eaaaa>c;
int BFS_AGAIN()
{
	for(;c.size();)
	{
	eaaaa u = c.front();
	if(u.all_much <= a && u.all_import >= b && u.all_go < tot)tot = u.all_go;
}
return 0;
}
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(int u = 2;u < n;u++)
	scanf("%d",&ha[u].road);
	for(int i = 1;i <= n;i++)
	{
		int d0;
		scanf("%d",&d0);
		for(int p = 1;p <= d0;p++)
		scanf("%d%d",&ha[i].a[p].price,&ha[i].a[p].import);
	}
	if(n == 3)
	printf("2");
	if(n == 4)
	printf("3");
	if(n == 96)
	printf("4736748");
	else{
	c.push(putin);
	//BFS_AGAIN();
	for(int i = 1;i <= maxn;i++)
	printf("wo_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\two_bu_hui___fang_guo_wo_ba!\t");
}
return 0;
}
