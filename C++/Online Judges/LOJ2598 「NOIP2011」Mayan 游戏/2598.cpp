#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[6][10][10];
int ans[10][3];
bool b[10][10];
bool isok;
int n, i, j, x;
inline bool clear(int a[10][10]){
    int i, j;
    bool flag;
    memset(b, 0, sizeof(b));
    for(i=1; i<=5; i++){
        for(j=1; j<=7; j++) if(a[i][j]){
            if(a[i][j]==a[i-1][j] and a[i][j]==a[i+1][j]) flag=b[i][j]=b[i-1][j]=b[i+1][j]=1;
            if(a[i][j]==a[i][j-1] and a[i][j]==a[i][j+1]) flag=b[i][j]=b[i][j-1]=b[i][j+1]=1;
        }
    }
    for(i=1; i<=5; i++)
        for(j=1; j<=7; j++)
            a[i][j]=a[i][j]*!b[i][j];
    return flag;
}
inline void down(int a[10][10]){
    int i, j, k;
    for(i=1; i<=5; i++){
        k=0;
        for(j=1; j<=7; j++) if(a[i][j]) a[i][++k]=a[i][j];
        for(j=k+1; j<=7; j++) a[i][j]=0;
    }
}
void dfs(int p){
    if(isok) return;
    int i, j;
    for(i=1; i<=5 and !a[p][i][1]; i++);
    if(i>5){
        if(p==n){
            isok=1;
            for(i=0; i<n; i++) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
        }
    }
    if(p>=n) return;
    for(i=1; i<=5; i++){
        for(j=1; a[p][i][j]; j++){
            if(i<5 and a[p][i][j]^a[p][i+1][j]){
                memcpy(a[p+1], a[p], sizeof(a[p]));
                swap(a[p+1][i][j], a[p+1][i+1][j]);
                do down(a[p+1]); while(clear(a[p+1]));
                ans[p][0]=i-1; ans[p][1]=j-1; ans[p][2]=1;
                dfs(p+1);
            }
            if(i-1 and !a[p][i-1][j]){
                memcpy(a[p+1], a[p], sizeof(a[p]));
                swap(a[p+1][i][j], a[p+1][i-1][j]);
                do down(a[p+1]); while(clear(a[p+1]));
                ans[p][0]=i-1; ans[p][1]=j-1; ans[p][2]=-1;
                dfs(p+1);
            }
        }
    }
}
int main(){
    // freopen("2598.in", "r", stdin);
    // freopen("2598.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=5; i++){
        j=0;
        scanf("%d", &x);
        while(x){
            a[0][i][++j]=x;
            scanf("%d", &x);
        }
    }
    dfs(0);
    if(!isok) printf("-1\n");
    return 0;
}
