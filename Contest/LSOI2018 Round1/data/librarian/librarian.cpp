#include <cstdio>
using namespace std;
char s[105][105], a[105];
bool vis[105];
int n, m, i, j;
inline bool strcmp(char *a, char *b){
    while(*a or *b) if((*a++)^(*b++)) return 0;
    return 1;
}
int main(){
    #ifndef STDIO
    freopen("librarian.in", "r", stdin);
    freopen("librarian.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%s", s[i]);
    for(i=1; i<=m; i++){
        scanf("%d %s", &j, a);
        for(j=1; j<=n and (vis[j] or !strcmp(a, s[j])); j++);
        if(j<=n){
            printf("1\n");
            vis[j]=1;
        }
        else printf("0\n");
    }
    return 0;
}
