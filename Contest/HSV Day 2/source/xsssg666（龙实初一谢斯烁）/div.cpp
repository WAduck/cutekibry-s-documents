#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
 double a,t,c,d[100];char b[100];
int main() 
{
   scanf("%lf",&t);
   for(int i=1;i<=t;i++)
   {
   	scanf("%lf",&a);
   	scanf("%s",&b);
   	if(strlen(b)>7)
       {
       	int y=(int)a;
       	printf("%d/",y);
        printf("%s",b);
       	printf("=0.000\n");
        } 
        else 
        {
            int la=strlen(b);
            for(int i=0;i<=la;i++) d[la-1-i]=b[i]-'0';  
            float f=d[6]*1000000+d[5]*100000+d[4]*10000+d[3]*1000+d[2]*100+d[1]*10+d[0];
      double c=a/f;
      int y=(int)a;
      int e=(int)f;
      printf("%d/%d=%.3lf\n",y,e,c);
        }
   }
return 0;
}

