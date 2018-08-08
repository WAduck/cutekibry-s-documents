// luogu-judger-enable-o2
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdlib>
#define maxn 1000000+20
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define write(a) printf("%lld",a)
#define writeln printf("\n")
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
using namespace std;
int abs(int a){
    if(a<0)return -a;
    return a;
}
inline ull read(){
    ull x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9'){
        if (c=='-')f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
char b[120];
int main(){
    int n=read(),a,len,num;
    FOR(i,1,n){
        scanf("%d %s",&a,b);
        printf("%d/%s=",a,b);
        len=strlen(b);
        if(len<=7){
            num=0;
            FOR(j,0,len-1)num=num*10+b[j]-'0';
            printf("%.3lf\n",(double)a*1.000000/num*1.000000);
        }else printf("0.000\n");
    }
    return 0;
}
