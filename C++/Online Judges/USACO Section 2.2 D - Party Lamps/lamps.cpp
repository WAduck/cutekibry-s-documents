/*
ID: TsukXmaru Oshawott
LANG: C++
TASK: lamps
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, i, temp;
struct string{
    char a[105];
    void writeln(){
        int i;
        for(i=1; i<=n; i++) putchar(a[i]|48);
        putchar('\n');
    }
    string operator = (string b){
        memcpy(a, b.a, sizeof(b.a));
        return *this;
    }
    bool operator < (string b){
        for(i=1; i<=n; i++) if(a[i]^b.a[i]) return a[i]<b.a[i];
        return false;
    }
    bool operator == (string b){
        for(i=1; i<=n; i++) if(a[i]^b.a[i]) return false;
        return true;
    }
};
string ans[25], dfsa, lim; int cnt;
void dfs(int p, int less){
    int i;
    if(p>4){
        for(i=1; i<=n and dfsa.a[i]^lim.a[i]; i++);
        if(i>n) ans[++cnt]=dfsa;
        return;
    }
    dfs(p+1, less);
    if(less){
        for(i=1; i<=n; i++){
            if(p==1) dfsa.a[i]^=1;
            else if(p==2) dfsa.a[i]^=i&1;
            else if(p==3) dfsa.a[i]^=~i&1;
            else if(p==4) dfsa.a[i]^=i%3==1;
        }
        dfs(p+1, less-1);
        for(i=1; i<=n; i++){
            if(p==1) dfsa.a[i]^=1;
            else if(p==2) dfsa.a[i]^=i&1;
            else if(p==3) dfsa.a[i]^=~i&1;
            else if(p==4) dfsa.a[i]^=i%3==1;
        }
    }
}
int main(){
    memset(lim.a, '.', sizeof(lim.a));
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) dfsa.a[i]=1;
    scanf("%d", &temp);
    while(~temp){
        lim.a[temp]=0;
        scanf("%d", &temp);
    }
    scanf("%d", &temp);
    while(~temp){
        if(!lim.a[temp]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
        lim.a[temp]=1;
        scanf("%d", &temp);
    }
    dfs(1, m);
    sort(ans+1, ans+1+cnt);
    cnt=unique(ans+1, ans+1+cnt)-ans-1;
    for(i=1; i<=cnt; i++) ans[i].writeln();
    if(!cnt) printf("IMPOSSIBLE\n");
    return 0;
}
