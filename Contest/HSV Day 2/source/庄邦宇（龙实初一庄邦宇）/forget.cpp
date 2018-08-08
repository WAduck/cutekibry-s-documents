#include<cstdio>
using namespace std;
int do_[100][100];
int jd[100];
int n,m;
int day = 1;
int max;
int max2;
int fnl;
int find = 1;
int should;
int justforgetzn()
{
    for(int u = 0;u <= m-1;u++)
    {
    if(do_[u][jd[u]] > max){max = do_[u][jd[u]];find = 1;}
    if(do_[u][jd[u]] == max)find += 1;
}
    if(find > 1)for(int r = 0;r <= m-1;r++)
    {
        if(do_[r][jd[r]] == max && do_[r][jd[r]+1] > max2){max2 = do_[r][jd[r]+1];should = r;}
    }
    fnl+=max;
    jd[should]+=1;
    max = 0;
    max2 = 0;
    if(day == n)return 0;
    else {day+=1;justforgetzn();}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i <= m-1;i++)
    {
        for(int k = 0;k <= n-1;k++)
        scanf("%d",&do_[i][k]);
    }
    justforgetzn();
    printf("%d",fnl);
    return 0;
}