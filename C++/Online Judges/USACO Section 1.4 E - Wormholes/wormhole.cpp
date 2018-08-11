/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: wormhole
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int i, j;
int ax[18], ay[18];
int link[18];
int right[18];
int cnt[18];
int n;
int ans;
inline bool judge(){
    int i, j;
    for(i=1; i<=n; i++){
        j=i;
        memset(cnt, 0, sizeof(cnt));
        while(j){
            j=right[j];
            cnt[j]++;
            j=link[j];
            cnt[j]++;
            if(cnt[j]>=3) return true;
        }
    }
    return false;
}
void dfs(int p){
    int i, j;

    if(p>n){
        if(judge()){
            ans++;
            // for(i=1; i<=n; i++) printf("%d ", link[i]);
            // printf("\n");
        }
        return;
    }
    if(link[p])
        dfs(p+1);
    else{
        for(i=p+1; i<=n; i++) if(!link[i]){
            link[p]=i;
            link[i]=p;
            dfs(p+1);
            link[p]=0;
            link[i]=0;
        }
    }
}
int main(){
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    scanf("%d", &n);
    ax[0]=2e9;
    for(i=1; i<=n; i++) scanf("%d %d", &ax[i], &ay[i]);
    for(i=1; i<=n; i++) for(j=1; j<=n; j++) if(i^j and ay[i]==ay[j] and ax[i]<ax[j] and ax[j]<ax[right[i]])
        right[i]=j;
    // for(i=1; i<=n; i++) printf("%d ", right[i]);
    // printf("\n\n");
    dfs(1);
    printf("%d\n", ans);
	return 0;
}
