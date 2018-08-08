#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char b[100000];
double cti()
{
    int len=strlen(b);
    long long ans=0,ws=len;
    for(register int i=0;i<len;i++)
    {
        ans+=(b[i]-'0')*pow(10,ws);
        ws--; 
    }
    return ans/10;
}
int main()
{	
    double a,b1,ga=0;
    int t;
    scanf("%d",&t); 
    for(register int i=1;i<=t;i++)
    {
        scanf("%lf",&a);
        scanf("%s",b);
        printf("%.0lf/",a);
        printf("%s",b);
        printf("=");
        b1=cti();	
        if(b1>=a*10000)
        {
            printf("%.3lf",ga);
            continue;
        }
            printf("%.3lf\n",a/b1);
    }
    return 0;
 } 