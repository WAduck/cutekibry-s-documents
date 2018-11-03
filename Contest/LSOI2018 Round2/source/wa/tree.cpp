#include <cstdio>
using namespace std;
char s[100005], pat[10]="freopen";
inline bool strcmp(char *a, char *b){
    while(*b) if((*a++)^(*b++)) return 0;
    return 1;
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int i, ans=0;
    scanf("%s", s);
    for(i=0; s[i]; i++) ans+=strcmp(s+i, pat);
    printf("%d\n", ans);
    return 0;
}
