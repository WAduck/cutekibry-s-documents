#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
int a;
cin>>a;
unsigned long long int b[a+1],sum1=0;
for(int u=1;u<=a;u++)
{
scanf("%lld",&b[u]); 
sum1+=b[u];
}
int y;
cin>>y;
for(int u=1;u<=y;u++)
{
int sum=sum1,sum2=0;
int akioi;
cin>>akioi;
sum=(int)((double)sum/(double)a+0.5);
if(sum>akioi)sum=akioi;
for(int u=1;u<=a;u++)
{
sum2+=(b[u]+sum)*(b[u]+sum);
}
cout<<sum2/sum<<endl;
}
return 0;
}
