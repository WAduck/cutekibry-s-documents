#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline int read()
{
int ret=0,f=1;char ch=getchar();
while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
return ret*f;
}
int main()
{
freopen("score.in","r",stdin);
freopen("score.out","w",stdout);
int n=read(),m=read(),max2,max1;
double zy=0,test=0,qm;
int a[n+1],b[m+1];
for(int u=1;u<=n;u++)
{
a[u]=read();
zy+=a[u];
}
zy=zy/(double)n;
for(int u=1;u<=m;u++)
{
b[u]=read();
}
for(int u=1;u<=m;u++)
{
if(b[u]>=max1)
{
max1=b[u];
continue;
}
if(b[u]>=max2)
{
max2=b[u];
}
}
cin>>qm;
double QAQ=zy*0.2+max2*0.3+qm*0.5+0.5;
cout<<(int)QAQ;
return 0;
}
