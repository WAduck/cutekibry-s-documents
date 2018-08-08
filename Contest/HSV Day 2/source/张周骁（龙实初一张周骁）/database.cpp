#include<iostream>
#include<cstring>
using namespace std;
char a1[50001][6],a2[50001][6],a3[50001][6],a4[50001][6],a5[50001];
int main()
{
int a;
cin>>a;
int b1=a,b2=a,b3=a,b4=a,b5=a;
for(int w=1;w<=a;w++)
{
cin>>a1[w]>>a2[w]>>a3[w]>>a4[w];
}
for(int w=1;w<=a;w++)
{
for(int e=w+1;e<=a;e++)
{
if(strcmp(a1[w],a1[e])==0&&strcmp(a2[w],a2[e])==0&&strcmp(a3[w],a3[e])==0&&strcmp(a4[w],a4[e])==0&&a5[w]==0)
{
b1--;
a5[e]++;
}
if(strcmp(a2[w],a2[e])==0&&strcmp(a3[w],a3[e])==0&&strcmp(a4[w],a4[e])==0&&a5[w]==0)
{
b2--;
a5[e]++;
}
if(strcmp(a1[w],a1[e])==0&&strcmp(a3[w],a3[e])==0&&strcmp(a4[w],a4[e])==0&&a5[w]==0)
{
b3--;
a5[e]++;
}
if(strcmp(a1[w],a1[e])==0&&strcmp(a2[w],a2[e])==0&&strcmp(a4[w],a4[e])==0&&a5[w]==0)
{
b4--;
a5[e]++;
}
if(strcmp(a1[w],a1[e])==0&&strcmp(a2[w],a2[e])==0&&strcmp(a3[w],a3[e])==0&&a5[w]==0)
{
b5--;
a5[e]++;
}
}
}
cout<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<" "<<b5;
return 0;
}