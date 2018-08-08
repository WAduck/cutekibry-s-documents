#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,d,e,i,j;
    i<n;j<n;
    string f[n],g[n],h[n],k[n];
    cin>>n;
    for(i=0;i<=n;i++) cin>>f[i]>>g[i]>>h[i]>>k[i];
    a=n;
    if((g[i]==g[j])&&(h[i]==h[j])&&(k[i]==k[j]))
    b=n-1;
    if((f[i]!=g[j])||(h[i]!=h[j])||(k[i]==k[j]))
    c=n;
    if((f[i]==f[j])&&(g[i]==g[j])&&(k[i]==k[j]))
    d=n-1;
    if((f[i]==f[j])&&(g[i]==g[j])&&(h[i]==h[j]))
    e=n-1;
    cout<<a<<b<<c<<d<<e<<endl;
    return 0;
}
