#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,a[t],b[t],i;
    double c[i];
    cin>>t;
    for(int i=0;i<t;i++)
    cin>>a[i]>>b[i];
    c[i]=a[i]/b[i];
    cout<<a[i]<<"/"<<b[i]<<"=";printf("%.3f",c[i]);
    cout<<endl;
    c[i+1]=a[i+1]/b[i+1];
    cout<<a[i+1]<<"/"<<b[i+1]<<"=";printf("%.3f",c[i+1]);
    cout<<endl;
    return 0;
}