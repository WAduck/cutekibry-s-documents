/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: camelot
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MX[]={1, 2, -1, -2, 1, 2, -1, -2}, MY[]={2, 1, 2, 1, -2, -1, -2, -1};
const int EPS=10, INF=0x3f3f3f3f;
int dis[32][32][32][32];
int n, m, x, y, i, j, k, l, o, kingx, kingy, sum, ans=INF;
int knightx[32*32], knighty[32*32], knightn;
int qx[32*32], qy[32*32], ql, qr;
char ch;
inline int abs(int x){ return (x<0)?-x:x; }
inline void bfs(int sx, int sy){
    int k, ux, uy, vx, vy;
    dis[sx][sy][sx][sy]=0;
    qx[ql=1]=sx;
    qy[qr=1]=sy;
    while(ql<=qr){
        ux=qx[ql];
        uy=qy[ql++];
        for(k=0; k<8; k++){
            vx=ux+MX[k];
            vy=uy+MY[k];
            if(vx>=1 and vy>=1 and vx<=n and vy<=m and dis[sx][sy][ux][uy]+1<dis[sx][sy][vx][vy]){
                dis[sx][sy][vx][vy]=dis[sx][sy][ux][uy]+1;
                qx[++qr]=vx;
                qy[qr]=vy;
            }
        }
    }
}
int main(){
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) bfs(i, j);
    scanf(" %c %d", &ch, &x);
    kingx=x;
    kingy=ch-64;
    while(~scanf(" %c %d", &ch, &x)){
        knightx[++knightn]=x;
        knighty[knightn]=ch-64;
    }
    for(i=max(1, kingx-EPS); i<=kingx+EPS and i<=n; i++){
        for(j=max(1, kingx-EPS); j<=kingx+EPS and j<=m; j++){
            sum=0;
            for(k=1; k<=knightn; k++) sum+=dis[knightx[k]][knighty[k]][i][j];
            ans=min(ans, sum+min(abs(kingx-i), abs(kingy-j)));
            for(k=1; k<=knightn; k++){
                for(l=max(1, kingx-EPS); l<=kingx+EPS and l<=n; l++){
                    for(o=max(1, kingx-EPS); o<=kingx+EPS and o<=m; o++){
                        ans=min(ans, sum
                                    -dis[knightx[k]][knighty[k]][i][j]
                                    +dis[knightx[k]][knighty[k]][l][o]
                                    +min(abs(kingx-l), abs(kingy-o))
                                    +dis[l][o][i][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
