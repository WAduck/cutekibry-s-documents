#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
char a;
int jd=0,zby=0,flag=0;
while(a!=EOF)
{
if(flag==0)a=getchar();
if(a=='f'){
flag=1;
a=getchar();
if(a=='r')
{
a=getchar();
if(a=='e')
{
a=getchar();
if(a=='o')
{
a=getchar();
if(a=='p')
{
a=getchar();
if(a=='e')
{
a=getchar();
if(a=='n')
{
zby++;
}
}
}
}
}
}
}
else{
flag=0;
}
}
cout<<zby;
return 0;
}
