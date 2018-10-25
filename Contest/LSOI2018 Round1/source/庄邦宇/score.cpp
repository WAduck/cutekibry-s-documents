#include<cstdio>
#include<algorithm> 
using namespace std;
int n,m;
double homework;
int plu;
int score[300010];
double fnl_score;
double fnl;
const float chk = 0.5;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
	scanf("%d",&plu);
	homework+=plu;
}
for(int k = 1;k <= m;k++)
scanf("%d",&score[k]);
scanf("%lf",&fnl);
sort(score+1,score+m+1);
plu = 1;
int hh = score[m];
for(int j = m;j;j--)
{
	if(hh != score[j]){plu+=1;hh = score[j];}
	if(plu == 2)break;
}
fnl_score = hh;
homework/=n;
printf("%.0f",homework*0.2+fnl_score*0.3+fnl*0.5);
	return 0;
}
