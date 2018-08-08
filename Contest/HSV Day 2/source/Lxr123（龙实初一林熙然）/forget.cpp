#include<iostream>
using namespace std;
int main()
{
    int a[360][360],m,n,k=0,s=0,p;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    cin>>a[i][j];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>k)
            {
            p=a[i][j];
            k=p;
            }
            else
            p=k;
    }
    s+=p;
    p=0;
    k=0;
}
    cout<<s;
    return 0;
}