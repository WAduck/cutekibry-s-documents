#include<cstdio>
using namespace std;
int main()
{
    double t,a,b,c,d;
    scanf("%f",&t)endl;
    scanf("%f","%f",&a,&b)endl;
    scanf("%f","%f",&b,&a)endl;
    c=a/b;
    d=b/a;
    printf(a,"/",b,"=","%.3lf",c)endl;
    printf(b,"/",a,"=","%.3lf",d)endl;
    return 0;
}