#include<iostream>
#include<algorithm>
using namespace std;
int f1[100001],f2[100001],f3[100001],f1n=0,f2n=0,f3n=0,ans=0;
inline int read(){int ret=0,f=1;char ch=getchar();while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();return ret*f;}
int main()
{
freopen("chocolate.in","r",stdin);
freopen("chocolate.out","w",stdout);
int a,b,c;
cin>>a>>b>>c;
for(int u=1;u<=a;u++)
{
int h=read(),y=read();
if(h==1)
{
f1n++;
f1[f1n]=y;
}
if(h==2)
{
f2n++;
f2[f2n]=y;
}
if(h==3)
{
f3n++;
f3[f3n]=y;
}
}
sort(f1+1,f1+1+f1n);
sort(f2+1,f2+1+f2n);
sort(f3+1,f3+1+f3n);
int l=b;
int m=c;
int h=1;
while((f3[h]<f1[l]||f3[h]<f2[m])&&h<=f3n)
{
if(f2[m]>f1[l])
{
f2[m]=f3[h];
h++;
m--;
}
else{
f1[l]=f3[h];
h++;
l--;
}
}
for(int u=1;u<=b;u++)ans+=f1[u];
for(int u=1;u<=c;u++)ans+=f2[u];
if(f1n+f2n<f3n)
{
for(int u=h;u<=h+f3n-f1n-f2n;u++)ans+=f3[u];
}
cout<<ans;
return 0;
}
