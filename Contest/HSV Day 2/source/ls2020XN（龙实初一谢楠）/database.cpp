#include<iostream>
#include<string>
using namespace std;
int n,sum1,sum2,sum3,sum4,sum5;
string a[1000],b[1000],c[1000],d[1000];
int main()
{
    cin>>n;
    sum1=sum2=sum3=sum4=sum5=n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if((a[i]==a[j])&&(b[i]==b[j])&&(c[i]==c[j])&&(d[i]==d[j]))
            sum1--;
        }
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if((b[i]==b[j])&&(c[i]==c[j])&&(d[i]==d[j]))
            sum2--;
        }
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if((a[i]==a[j])&&(c[i]==c[j])&&(d[i]==d[j]))
            sum3--;
        }
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if((a[i]==a[j])&&(b[i]==b[j])&&(d[i]==d[j]))
            sum4--;
        }
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if((a[i]==a[j])&&(b[i]==b[j])&&(c[i]==c[j]))
            sum5--;
        }
    }
    cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<" "<<sum5;
}