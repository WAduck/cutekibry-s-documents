#include <cstdio>
using namespace std;
int a[105], x;
int n, m, i, j;
int main(){
    #ifndef STDIO
    freopen("librarian.in", "r", stdin);
    freopen("librarian.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    for(i=1; i<=m; i++){
        scanf("%d %d", &j, &x);
        for(j=1; j<=n and x^a[j]; j++);
        if(j<=n){
            printf("1\n");
            a[j]=0;
        }
        else printf("0\n");
    }
    return 0;
}
