#include<iostream>
using namespace std;
long long int f(long long int p)
{
if(p==0)return 1;
long long int tmp=f(p/2)%1000000007;                       
tmp=(tmp*tmp)%1000000007;
if(p%2==1)tmp=(tmp*2)%1000000007;
return tmp;
}
int main()
{
freopen("cinnamoroll.in","r",stdin);
freopen("cinnamoroll.out","w",stdout);
long long int a,b,e,r;
cin>>a>>b;
long long int num=a;
if(b==1)
{
cin>>e;
num-=a/e;
if(a%e==0||e==1)
{
cout<<"0";
return 0;
}
}
if(b==2)
{
cin>>e>>r;
num=num-a/e-a/r+a/(e*r);
if(a%e==0||e==1||a%r==0||r==1)
{
cout<<"0";
return 0;
}
}
cout<<f(num-2)%1000000007;
return 0;
}
