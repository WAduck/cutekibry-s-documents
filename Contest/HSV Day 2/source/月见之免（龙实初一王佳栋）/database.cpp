#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
ull all[50001];
ull name[50001];
ull school[50001];
ull she[50001];
ull age[50001];
char a[7],b[7],c[7],d[7],xj[49];
int anser[5];
ull base=131;
int n,ans=1;
int prime=233317; 
ull mod=2123740130137957ll;
ull hashe(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
    ans=(ans*base+(ull)s[i])%mod+prime;
    return ans;
}
int main()
{
    int n,a1,a2,a3,a4; 
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);
        scanf("%s",d);
        a1=hashe(a);
        a2=hashe(b);
        a3=hashe(c);
        a4=hashe(d);
        all[i]=a1+a2+a3+a4;
        name[i]=a2+a3+a4;
        she[i] = a1+a3+a4;
        age[i]=a1+a2+a4;
        school[i]=a2+a3+a4; 
    } 
    sort(all+1,all+n+1);
    sort(name+1,name+n+1);
    sort(she+1,she+n+1);
    sort(age+1,age+n+1);
    sort(school+1,school+n+1);
    for(register int i=1;i<=n;i++)
    {
        if(all[i]!=a[i-1])
            anser[1]++;
        if(name[i]!=name[i-1])
            anser[2]++;
        if(she[i]!=she[i-1])
            anser[3]++;
        if(age[i]!=age[i-1])
            anser[4]++;
        if(school[i]!=school[i-1])
            anser[5]++;	
    }
    for(register int i=1;i<=5;i++)
        printf("%d ",anser[i]);
    return 0;
}