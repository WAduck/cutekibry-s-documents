#include<iostream>
#include<algorithm>
using namespace std;
int b[3000000];
int sum=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    int n,m;
    int qi;
    int zum;
    int a;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        sum+=a;
    }
    for(int j=1;j<=m;j++)
    {
        cin>>b[j];
    }
    sort(b+1,b+1+m,cmp);
    for(int h=1;h<=m;h++)
    {
        if(b[h]!=b[h+1])
        {
            zum=b[h+1];
            break;
        }
    }
    cin>>qi;
    //cout<<sum/n<<" "<<zum<<" "<<qi<<endl;
    int zong=(sum/n)*0.2+zum*0.3+qi*0.5;
    cout<<zong;
    return 0;
}