#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int x[1001];
int a[1001];
long long int qiu[10001];
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	int n;int q;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x[i];
	}
	sort(x+1,x+1+q);
	for(int j=1;j<=x[q];j++)
	{
		for(int i=1;i<=n;i++)
		{
			qiu[j]+=pow((a[i]+j),2);
		}
		qiu[j]=qiu[j]/j;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<qiu[x[i]]<<endl;
	}
	return 0;
}