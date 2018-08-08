#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct xss
{
    char name[10];
    char dq[10];
    int age;
    char xx[10];
}a[50000];
int main()
{
    int n;
    int q,w,e,r,t;
    scanf("%d",&n);
    q=n;
    w=n;
    e=n;
    r=n;
    t=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&a[i].name);
        scanf("%s",&a[i].dq);
        scanf("%d",&a[i].age);
        scanf("%s",&a[i].xx);
    }
    for(int j=1;j<=n;j++)
    {
        for(int k=j+1;k<=n;k++)
        {
        if(strcmp(a[j].dq,a[k].dq)==0&&strcmp(a[j].xx,a[k].xx)==0&&strcmp(a[j].name,a[k].name)==0&&a[j].age==a[k].age)
        {
        q--;
       }
       if(strcmp(a[j].dq,a[k].dq)==0&&strcmp(a[j].xx,a[k].xx)==0&&a[j].age==a[k].age)
        {
        w--;
       }
       if(strcmp(a[j].xx,a[k].xx)==0&&a[j].age==a[k].age&&strcmp(a[j].name,a[k].name)==0)
        {
        e--;
       }
       if(strcmp(a[j].dq,a[k].dq)==0&&strcmp(a[j].name,a[k].name)==0&&strcmp(a[j].xx,a[k].xx))
        {
        r--;
       }if(strcmp(a[j].dq,a[k].dq)==0&&strcmp(a[j].name,a[k].name)==0&&a[j].age==a[k].age)
        {
        t--;
       }
        }
    }
    
    printf("%d %d %d %d %d",q,w,e,r,t);
    return 0;
} 

