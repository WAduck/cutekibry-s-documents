#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long int i, a[10000]={0};
void dec(int x, int y, int z);
void output(int x, int y, int z);
int main()
{
int p;
cin>>p;
for(int e=1;e<=p;e++)
{
long long int a, b, n=3;
scanf("%lld%lld", &a, &b);
cout<<a<<"/"<<b<<"=";
dec(a%b, b, n);
output(a, b, n);
}
return 0;
}
void dec(int x, int y, int z)
{
for (i=0; i<=z; i++)
{
x *= 10;
a[i] = x/y;
x %= y;
}
}
void output(int x, int y, int z)
{
int t=x/y;
if (z >= 1)
{
if (a[z] > 4)
a[z-1]++;
if (z > 1)
{
for (i=z-1; i>=1; i--)
if (a[i] > 9)
{
a[i] = 0;
a[i-1]++;
}
}
if (a[0] > 9)
{
a[0] = 0;
t++;
}
}
else if (z == 0)
if (a[0] > 4)
t++;
printf("%ld", t);
if (z)
printf(".");
for (i=0; i<z; i++)
printf("%d", a[i]);
printf("\n");
}