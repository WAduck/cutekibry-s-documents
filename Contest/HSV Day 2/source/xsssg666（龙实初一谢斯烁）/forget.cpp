#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct xss{
    int num;
    int dj;
}a[10000];
bool cmp(xss a,xss b)
{
    return a.dj<b.dj;
}
int main()
{
    int n,m,max=0,djmax=0,sum=0,d,s=0;
            int b=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            scanf("%d",&d);
            s+=d; 
            a[i].num=s; 
            a[i].dj=b;
            b++;
            if(b==n+1){
            b=1;
            s=0;
        }
}
sort(a+1,a+1+n*m,cmp);
for(int j=1;j<=n;j++)
{
    for(int h=0;h<=n-1;h++)
    {
        djmax+=a[j+h].dj;
        max+=a[j+h].num;
    }
    if(djmax==n&&max>sum)
    {
        sum=max;
    }
    else{
        djmax=0;max=0;
    }
}
    cout<<sum;
    return 0;
}