#include <cstdio>
#include <algorithm>
using namespace std;
inline int id(char x){ return (x<='Z')?(x-'A'+1):(x-'a'+27); }
inline char ch(int x){ return (x<=26)?(x+'A'-1):(x+'a'-27); }
bool w[66][66];
int deg[66];
int s[5005], stop;
char ch1, ch2;
int ctr, i, j, tmp, u, v, n, m;
void findpath(int u){
    int i;
    for(i=1; i<=n; i++) if(w[u][i]){
        w[u][i]=w[i][u]=0;
        findpath(i);
    }
    s[++stop]=u;
}
int main(){
    n=52;
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf(" %c%c", &ch1, &ch2);
        u=id(ch1);
        v=id(ch2);
        w[u][v]=w[v][u]=1;
        deg[u]++;
        deg[v]++;
    }
    for(i=1; i<=n; i++) ctr+=deg[i]&1;
    if(!ctr){
        for(i=1; i<=n and !deg[i]; i++);
        findpath(i);
    }
    else if(ctr==2){
        for(i=1; i<=n and !(deg[i]&1); i++);
        findpath(i);
    }
    else{
        printf("No Solution\n");
        return 0;
    }
    while(stop) putchar(ch(s[stop--]));
    return 0;
}
