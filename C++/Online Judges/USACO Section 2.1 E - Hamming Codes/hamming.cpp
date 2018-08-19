/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: hamming
*/
#include <cstdio>
using namespace std;
inline int dis(int x, int y){
    int res=0;
    while(x or y){
        res+=(x&1)^(y&1);
        x>>=1;
        y>>=1;
    }
    return res;
}
int n, b, d;
int a[70], an;
int vis[300];
bool ok;
void dfs(int p, int pre){
    int i, j;
    if(ok) return;
    if(p>n){
        ok=1;
        for(i=1; i<n; i++){
            printf("%d", a[i]);
            putchar((i%10)?' ':'\n');
        }
        printf("%d\n", a[n]);
        return;
    }
    for(i=pre+1; !(i>>b); i++){
        if(!vis[i]){
            a[p]=i;
            for(j=i+1; !(j>>b); j++) vis[j]+=dis(i, j)<d;
            dfs(p+1, i);
            for(j=i+1; !(j>>b); j++) vis[j]-=dis(i, j)<d;
            a[p]=0;
        }
    }
}
int main(){
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    scanf("%d %d %d", &n, &b, &d);
    dfs(1, -1);
    return 0;
}
