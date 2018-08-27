/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: agrinet
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int f[105];
int gf(int x){
    if(x^f[x]) return f[x]=gf(f[x]);
    else return x;
}
bool check(int x, int y){
    return !(gf(x)^gf(y));
}
void merge(int x, int y){
    f[gf(x)]=gf(y);
}
struct edge{
    int a, b, c;
};
bool cmp(edge a, edge b){
    return a.c < b.c;
}
edge w[10005]; int wn;
int main(){
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    int i, j;
    int n;
    int tmp;
    int ans=0;

    scanf("%d", &n);
    for(i=1; i<=n; i++) f[i]=i;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &tmp);
            if(i^j){
                w[++wn].a=i;
                w[wn].b=j;
                w[wn].c=tmp;
            }
        }
    }
    sort(w+1, w+1+wn, cmp);
    for(i=1; i<=wn; i++) if(!check(w[i].a, w[i].b)){
            merge(w[i].a, w[i].b);
            ans+=w[i].c;
        }
    printf("%d\n", ans);
    return 0;
}
