#include<cstdio>
#include<cstring>
using namespace std;
int a[200];
int fnl[10005][200];
char b[10005];
int hb;
int wei[200];
int t;
int l,c;
double ans[200];
int cnt(int turn)
{
    for(l = 10,c=1;l <= 10000;l*=10,c++)
    if(a[turn]%l==a[turn])break;
    if(c<wei[turn]-3){printf("%d/",a[turn]);for(int f = 1;f <= wei[turn];f++)printf("%d",fnl[f][turn]);printf("=0.000\n");}
    else if(b[0] == 1 && strlen(b) == 1){printf("%d/",a[turn]);for(int f = 1;f <= wei[turn];f++)printf("%d",fnl[f][turn]);printf("=%d.000\n",a[turn]);}
    else {
        double good = 0,v = a[turn];
        for(int g = wei[turn],m = 1;g >= 1;g--,m*=10)
        good+=fnl[g][turn]*m;
        printf("%d/",a[turn]);
        for(int f = 1;f <=wei[turn];f++)
        printf("%d",fnl[f][turn]);
        printf("=%.3f\n",v/good);
    }
    if(turn < t)cnt(turn+1);
}
int main()
{
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        int j = 1;
        
        scanf("%d",&a[i]);
        scanf("%s",b);
        for(int o = 1,p = 0;p <= strlen(b)-1;p++,o++)
        fnl[o][i] = b[p]-'0';
        wei[i] = strlen(b);
     }
     cnt(1);
     return 0;
 } 