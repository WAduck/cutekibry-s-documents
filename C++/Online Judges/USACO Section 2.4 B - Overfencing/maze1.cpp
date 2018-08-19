/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: maze1
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/6;
const int MX[]={1, 0, -1, 0}, MY[]={0, 1, 0, -1};
int i, j, k, n, m, temp;
char a[205][105];
int dis[205][105];
int qx[SCP], qy[SCP], ql, qr, ux, uy, vx, vy, ans=0;
inline int bfs(int x, int y){
    memset(dis, 0x3f, sizeof(dis));
    dis[x][y]=0;
    qx[ql=1]=x;
    qy[qr=1]=y;
    while(ql<=qr){
        ux=qx[ql];
        uy=qy[ql++];
        for(k=0; k<4; k++){
            vx=ux+MX[k];
            vy=uy+MY[k];
            if(a[(ux<<1)+MX[k]][(uy<<1)+MY[k]]<=32 and dis[ux][uy]+1<dis[vx][vy]){
                if(!vx or !vy or vx>n or vy>m) return dis[ux][uy];
                dis[vx][vy]=dis[ux][uy]+1;
                qx[++qr]=vx;
                qy[qr]=vy;
            }
        }
    }
    return 0;
}
int main(){
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    scanf("%d %d\n", &m, &n);
    // printf("%d %d\n", m, n);
    for(i=1; i<=2*n+1; i++){
        for(j=1; j<=2*m+2; j++){
            a[i][j]=getchar();
            if(!(a[i][j]>>5)){
                a[i][j]=0;
                break;
            }
        }
    }
    // for(i=1; i<=2*n+1; i++){
    //     for(j=1; j<=2*m+1; j++){
    //         putchar(a[i][j]);
    //     }
    //     putchar('\n');
    // }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            temp=bfs(i, j);
            // printf("# %d %d %d\n", i, j, temp);
            ans=max(ans, temp);
        }
    }
    printf("%d\n", ans+1);
    return 0;
}
