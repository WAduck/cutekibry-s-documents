/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: stall4
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> to[205];
int match[205];
bool vis[205];
bool dfs(int p){
    int i;
    vector<int>::iterator it;

    for(it=to[p].begin(); it!=to[p].end(); it++){
        i=*it;
        if(!vis[i]){
            vis[i]=true;
            if(!match[i] or dfs(match[i])){
                match[i]=p;
                return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    int i, j;
    int n, m;
    int s;
    int ans=0;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%d", &s);
        to[i].resize(s);
        for(j=0; j<s; j++)
            scanf("%d", &to[i][j]);
    }
    for(i=1; i<=n; i++){
        memset(vis, 0, sizeof(vis));
        ans+=dfs(i);
    }
    printf("%d\n", ans);
    return 0;
}
