/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: holstein
*/
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int i, j;
int needs[55];
int feeds[55][55];
int dfsa[55], dfsc[55];
int anscnt=50, ansa[55];
inline bool arrcmp(int *a, int *b){
    while(*a or *b){
        if((*a)^(*b)) return (*a)<(*b);
        a++; b++;
    }
    return false;
}
void dfs(int p, int cnt){
    if(cnt>anscnt) return;
    int i;
    for(i=1; i<=m and dfsc[i]>=needs[i]; i++);
    if(i>m){
        if(cnt<anscnt or arrcmp(dfsa+1, ansa+1)){
            memcpy(ansa, dfsa, sizeof(dfsa));
            anscnt=cnt;
            return;
        }
    }
    if(p>n) return;
    dfs(p+1, cnt);
    dfsa[cnt+1]=p;
    for(i=1; i<=m; i++) dfsc[i]+=feeds[p][i];
    dfs(p+1, cnt+1);
    for(i=1; i<=m; i++) dfsc[i]-=feeds[p][i];
    dfsa[cnt+1]=0;
}
int main(){
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    scanf("%d", &m);
    for(i=1; i<=m; i++) scanf("%d", &needs[i]);
    scanf("%d", &n);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) scanf("%d", &feeds[i][j]);
    dfs(1, 0);
    printf("%d", anscnt);
    for(i=1; i<=anscnt; i++) printf(" %d", ansa[i]);
    putchar('\n');
    return 0;
}
