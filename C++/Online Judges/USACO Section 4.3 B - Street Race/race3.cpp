/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: race3
*/
#include <cstdio>
#include <cstring>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
int i, j, k, n, m, x;
bool w[3][55][55], tw[3][55][55];
int a[55], atop, b[55], btop;
bool in[55], visa[55], visb[55];
inline void floyd(bool w[55][55]){
    int i, j, k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                w[i][j]|=w[i][k] and w[k][j];
}
inline void bfs(bool w[55][55], bool vis[55], int s, int stop){
    int i, j;
    int q[55], ql, qr;
    q[ql=qr=1]=s;
    vis[s]=1;
    while(ql<=qr){
        i=q[ql++];
        for(j=1; j<=n; j++) if(w[i][j] and !vis[j]){
            vis[j]=1;
            if(stop^j) q[++qr]=j;
        }
    }
}
int main(){
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    scanf("%d", &x);
    while(x!=-1){
        n++;
        while(x!=-2){
            if(n^(x+1)) w[0][n][x+1]=w[1][x+1][n]=w[2][n][x+1]=w[2][x+1][n]=1;
            scanf("%d", &x);
        }
        scanf("%d", &x);
    }
    for(x=2; x<n; x++){
        memcpy(tw, w, sizeof(w));
        for(i=1; i<=n; i++) tw[0][x][i]=tw[0][i][x]=0;
        floyd(tw[0]);
        if(!tw[0][1][n]) a[++atop]=x;
    }
    for(k=1; k<=atop; k++){
        x=a[k];

        // Judge 1.
        // 1: Each point can reach from the start.
        memcpy(tw, w, sizeof(w));
        memset(visa, 0, sizeof(visa)); bfs(tw[0], visa, 1, x);
        memcpy(in, visa, sizeof(visa));
        for(i=1; i<=n; i++) if(!in[i])
            for(j=1; j<=n; j++) tw[0][i][j]=tw[0][j][i]=tw[1][i][j]=tw[1][j][i]=0;
        // 2: The finish can be reached from any point.
        memset(visa, 0, sizeof(visa)); bfs(tw[1], visa, x, -1);
        for(i=1; i<=n and (!in[i] or visa[i]); i++);
        if(i<=n) continue;
        // 3: The finish has no outgoing edges.
        for(i=1; i<=n and !tw[0][x][i]; i++);
        if(i<=n) continue;

        // Judge 2.
        // 1: Each point can reach from the start.
        in[x]=0;
        memcpy(tw, w, sizeof(w));
        for(i=1; i<=n; i++) if(in[i])
            for(j=1; j<=n; j++) tw[0][i][j]=tw[0][j][i]=tw[1][i][j]=tw[1][j][i]=0;
        memset(visb, 0, sizeof(visb)); bfs(tw[0], visb, x, -1);
        for(i=1; i<=n and (in[i] or visb[i]); i++);
        if(i<=n) continue;
        // 2: The finish can be reached from any point.
        memset(visb, 0, sizeof(visb)); bfs(tw[1], visb, n, -1);
        for(i=1; i<=n and (in[i] or visb[i]); i++);
        if(i<=n) continue;
        // 3: The finish has no outgoing edges.
        for(i=1; i<=n and !tw[0][n][i]; i++);
        if(i<=n) continue;

        // No common points
        memset(visa, 0, sizeof(visa)); bfs(w[2], visa, 1, x);
        memset(visb, 0, sizeof(visb)); bfs(w[2], visb, n, x);
        for(i=1; i<=n and (i==x or visa[i]^visb[i]); i++);
        if(i<=n) continue;
        b[++btop]=x;
    }
    printf("%d", atop);
    for(i=1; i<=atop; i++) printf(" %d", a[i]-1);
    printf("\n%d", btop);
    for(i=1; i<=btop; i++) printf(" %d", b[i]-1);
    putchar('\n');
    return 0;
}
