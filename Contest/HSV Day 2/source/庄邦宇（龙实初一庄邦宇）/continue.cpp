// STL自带大常数，如果可以的话最好不要用
// 开个bool c[10005]之类的就可以了
// （虽然我看不太懂你在些什么（逃））
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
set<int>a;
set<int>b;
int n,m;
int fnl;
int row[200000];
int used[200000];
int push(int first,int second)
{
    for(int j = 1;j <= m;j++)
    a.insert((j%1000000007)*(row[first]%1000000007)%1000000007);
    for(int k = 1;k <= m;k++)
    a.insert((k%1000000007)*(row[second]%1000000007)%1000000007);
    fnl+=a.size()%10000000007;
    a.clear();
    if(second<n){push(first,second+1);used[second] = 1;}
    if(first<n-1 && used[first] != 1){used[first] = 1;first+=1;push(first,first+1);}
    else return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&row[i]);
    }
    push(1,2);
    printf("%d",fnl%10000000007);
    return 0;
}