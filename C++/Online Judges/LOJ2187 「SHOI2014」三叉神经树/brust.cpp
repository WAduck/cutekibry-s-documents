#include <cstdio>
using namespace std;
const int SCP=682*999/6;
int ch[SCP][3];
bool a[SCP];
int n, m, i, x;
int f(int u){
    return (ch[u][0])?(f(ch[u][0])+f(ch[u][1])+f(ch[u][2])>=2):a[u];
}
int main(){
    freopen("2187.in", "r", stdin);
    freopen("brust.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d %d %d", &ch[i][0], &ch[i][1], &ch[i][2]);
    for(i=n+1; i<=3*n+1; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d", &x);
        a[x]=!a[x];
        printf("%d\n", f(1));
    }
    return 0;
}
