#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char need[101][101],bm[101][101];
int qwertyuiopasdfghjklzxcvbnm,sf[101];
inline int read()
{
int ret=0,f=1;char ch=getchar();
while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
return ret*f;
}
int main()
{
freopen("librarian.in","r",stdin);
freopen("librarian.out","w",stdout);
int a=read(),b=read();
for(int u=1;u<=a;u++)cin>>bm[u];
for(int u=1;u<=b;u++)
{
qwertyuiopasdfghjklzxcvbnm=read();
cin>>need[u];
}
for(int o=1;o<=b;o++)
{
for(int u=1;u<=a;u++)
{
if(strcmp(bm[u],need[o])==0&&sf[u]==0)
{
puts("1");
sf[u]=1;
break;
}
if(u==a)puts("0");
}
}
return 0;
}
