#include <cstdio>
#include <cstring>
using namespace std;
const int BCP=682*999*2;
char a[BCP], b[BCP];
int nxt[BCP];
int i, j, n, m, ans;
int main(){
    scanf("%s %s", a+1, b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    for(i=2, j=0; i<=m; i++){
        while(b[i]^b[j+1] and j) j=nxt[j];
        if(b[i]==b[j+1]) j++;
        nxt[i]=j;
    }
    for(i=1, j=0; i<=n; i++){
        while(a[i]^b[j+1] and j) j=nxt[j];
        if(a[i]==b[j+1]) j++;
        if(j==m) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
