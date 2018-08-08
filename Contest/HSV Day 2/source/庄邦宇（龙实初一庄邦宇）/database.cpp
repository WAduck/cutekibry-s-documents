#include<cstdio>
#include<cstring>
using namespace std;
char xm[100000][10];
char sf[100000][10];
int nl[100000];
char xx[100000][10];
int A,B,C,D,E;
int n;
void del()
{
    for(int d = 1;d <= n;d++)
    {
        for(int t = d+1;t <= n;t++)
        {
        if(strcmp(xm[d],xm[t])== 0 && strcmp(sf[d],sf[t])== 0 && nl[d] == nl[t] && strcmp(xx[d],xx[t]) == 0)E+=1;
        if(strcmp(sf[d],sf[t])== 0 && nl[d] == nl[t] && strcmp(xx[d],xx[t]) == 0)A+=1;
        if(strcmp(xm[d],xm[t])== 0 && nl[d] == nl[t] && strcmp(xx[d],xx[t]) == 0)B+=1;
        if(strcmp(xm[d],xm[t])== 0 && strcmp(sf[d],sf[t])== 0 && strcmp(xx[d],xx[t]) == 0)C+=1;
        if(strcmp(xm[d],xm[t])== 0 && strcmp(sf[d],sf[t])== 0 && nl[d] == nl[t])D+=1;
    }	
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%s%s%d %s",xm[i],sf[i],&nl[i],xx[i]);
    }
    del();
    printf("%d %d %d %d %d",n-E,n-A,n-B,n-C,n-D);
    return 0;
 } 
