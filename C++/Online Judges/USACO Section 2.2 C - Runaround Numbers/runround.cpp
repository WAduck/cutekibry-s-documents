/*
ID: TsukXmaru Oshawott
LANG: C++
TASK: runround
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 P10[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
int a[25];
bool c[25];
int64 n;
int nextof(int64 x){
    int i, j;
    bool flag=1;
    while(flag){
        flag=0;
        for(i=1; x>=P10[i-1]; i++){
            if(!(x/P10[i-1]%10)) x+=P10[i-1], flag=1;
            for(j=i+1; x>=P10[j-1]; j++) if(x/P10[i-1]%10==x/P10[j-1]%10) x+=P10[i-1], flag=1;
        }
    }
    return x;
}
bool judge(int64 x){
    int i, j, sum=0, cnt=0;
    while(x){
        a[++cnt]=x%10;
        x/=10;
    }
    for(i=1, j=cnt; i<j; i++, j--) swap(a[i], a[j]);
    memset(c, 0, sizeof(c));
    i=1;
    while(!c[i]){
        c[i]=1;
        sum++;
        i=(i+a[i]-1)%cnt+1;
    }
    if(sum==cnt and i==1) return true;
    else return false;
}
int main(){
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    scanf("%lld", &n);
    n=nextof(n+1);
    while(!judge(n)) n=nextof(n+1);
    printf("%d\n", n);
    return 0;
}
