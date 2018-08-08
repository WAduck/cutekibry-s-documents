#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[51][51],vis[51][51],n,m,ans;
void dfs(int day,int x,int y,int bag)
 {

    if(day>=n or y>=n)
    {
        ans=max(ans,bag);
 		return ;
 	}
 	if(x!=0&&y!=0)
    {
        dfs(day+1,x,y+1,bag+a[x][y+1]);
    }for( int i=1;i<=m;i++)
    {
        if(i!=x)
            dfs(day+1,i,1,bag+a[i][1]);
    }

}
int main() 
{
    register int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    dfs(0,0,0,0);
    printf("%d",ans);
    return 0;
}