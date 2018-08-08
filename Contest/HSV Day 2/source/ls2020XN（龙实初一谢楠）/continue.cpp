#include<cstdio>
using namespace std;
int n,m,sum=0;
int main()
{
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i][1]);
        for(int j=2;j<=m;++j)
        {
            a[i][j]=a[i][1]*j;
        }
    }
    for(int x=1;x<=n-1;x++)
    {
        for(int y=x+1;y<=n;y++)
        {
            int f=2*n;
            for(int i=1;i<=m;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    if(a[x][i]==a[y][j])
                        f--;
                }
            }
            sum+=f;
        }
    }
    printf("%d",sum%1000000007);
    return 0;
}