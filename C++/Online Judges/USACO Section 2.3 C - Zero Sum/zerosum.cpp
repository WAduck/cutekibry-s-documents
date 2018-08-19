/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: zerosum
*/
#include <cstdio>
#include <algorithm>
using namespace std;
char s[50]; int stop;
int i, n;
int eval(){
    int i, res=0, temp=0, neg=1;
    for(i=1; i<=stop; i++){
        if(s[i]=='+') res=res+neg*temp, temp=0, neg=1;
        else if(s[i]=='-') res=res+neg*temp, temp=0, neg=-1;
        else if(s[i]^' ') temp=(temp<<3)+(temp<<1)+(s[i]&15);
    }
    return res+neg*temp;
}
void dfs(int p){
    if(p>n){
        if(!eval()) printf("%s\n", s+1);
        return;
    }
    if(p==1){
        s[++stop]='1';
        dfs(2);
        s[stop--]=0;
    }
    else{
        s[++stop]=' '; s[++stop]=p|48;
        dfs(p+1);
        s[stop--]=0; s[stop--]=0;
        s[++stop]='+'; s[++stop]=p|48;
        dfs(p+1);
        s[stop--]=0; s[stop--]=0;
        s[++stop]='-'; s[++stop]=p|48;
        dfs(p+1);
        s[stop--]=0; s[stop--]=0;
    }
}
int main(){
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    scanf("%d", &n);
    dfs(1);
    return 0;
}
