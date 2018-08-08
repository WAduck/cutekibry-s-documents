// 不是很懂你下面这个奇怪公式的意思
// c[100000000]不会炸？
#include<bits/stdc++.h>
using namespace std;
int c[100000000];
int main()
{
int a,b,aa,bb;
cin>>a>>b;
for(int p=1;p<=a;p++)
{
cin>>c[p]>>aa>>bb;
}
sort(c+1,c+a+1);
if(b%2==0)cout<<(c[a]+c[a-1])*(b/2);
else cout<<(c[a]+c[a-1])*(b/2)+c[a];
return 0;
}