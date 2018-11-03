#include <cstdio>
using namespace std;
const char *PATTERN="freopen";
char s[100005];
int n, i, j, ctr;
char ch;
int main(){
    #ifndef STDIO
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    #endif
    while(~(ch=getchar())) s[n++]=ch;
    for(i=0; i<n; i++){
        for(j=0; j<7 and s[i+j]==PATTERN[j]; j++);
        if(j>=7) ctr++;
    }
    printf("%d\n", ctr);
    return 0;
}
