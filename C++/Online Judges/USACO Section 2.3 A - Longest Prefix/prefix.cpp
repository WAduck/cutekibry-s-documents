/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: prefix
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
const int SCP=682*999/3;
char p[205][15]; int plen[205], m;
char s[SCP]; int n, i, j;
bool f[SCP];
inline bool softstrcmp(char *a, char *b){
    while(*a and *b) if((*a++)^(*b++)) return false;
    return true;
}
int main(){
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    do scanf("%s", p[++m]+1); while(p[m][1]^'.');
    m--;
    while(~scanf("%s", s+n+1)) n=strlen(s+1);
    for(i=1; i<=m; i++) plen[i]=strlen(p[i]+1);
    f[0]=1;
    for(i=0; i<=n; i++) if(f[i]){
        for(j=1; j<=m; j++) if(i+plen[j]<=n and softstrcmp(s+i+1, p[j]+1))
            f[i+plen[j]]=1;
    }
    // for(i=1; i<=n; i++) printf("%d ", f[i]);
    for(i=n; !f[i]; i--);
    printf("%d\n", i);
    return 0;
}
