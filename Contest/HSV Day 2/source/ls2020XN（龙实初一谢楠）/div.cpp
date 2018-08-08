#include<iostream>
#include<cstdio>
using namespace std;
int n;
double a[100000],b[100000],c[100000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        c[i]=a[i]/b[i];
    }
    for(int i=1;i<=n;++i)
    {
        cout<<a[i]<<"/"<<b[i]<<"=";
        printf("%0.3lf\n",c[i]);
    }
    return 0;
}