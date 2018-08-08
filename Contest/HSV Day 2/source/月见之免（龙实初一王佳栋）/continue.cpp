#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001]; 
int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y) ;
}
int main()
{
    int n,m,ans=0,b;
    scanf("%d%d",&n,&m);
    register int i,j;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        for(j=i+1;j<=m;j++)
            ans+=(2*m-(m*min(a[i],a[j])/(a[i]/gcd(a[i],a[j])*a[j])))%1000000007;
    printf("%d",ans);
    return 0;
}