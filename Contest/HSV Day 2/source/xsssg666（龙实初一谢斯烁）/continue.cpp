#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int sum=0; 
int n,m,x[1001];int b[10001];
int hb(int a,int c)
{
    for(int o=1;o<=m;o++)
    {
        b[o*3*a]=-1;
        b[o*3*c]=-1;
    }
    for(int g=1;g<=10001;g++)
    {
        if(b[g]==-1)sum++;
    }
    return sum;
} 
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int j=1;j<=n-1;j++)
    {
    	for(int h=j+1;h<=n;h++)
    	{
    		hb(x[j],x[h]);
    		memset(b, 0, sizeof(b));
        }
    }
    cout<<sum%10000007;
    return 0; 
}