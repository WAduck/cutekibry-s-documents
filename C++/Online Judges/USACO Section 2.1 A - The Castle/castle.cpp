/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: castle
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int F[]={2, 8, 1, 4}, MX[]={-1, 1, 0, 0}, MY[]={0, 0, -1, 1};
bool vis[55][55];
int qx[2505], qy[2505], ux, uy, ql, qr, temp;
int a[55][55], n, m, i, j;
int ans1, ans2, ans3, ans4[5];
inline int fill(int sx, int sy){
    int vx, vy, i;
    if(vis[sx][sy]) return 0;
    int ans=1;
    qx[ql=1]=sx;
    qy[qr=1]=sy;
    vis[sx][sy]=1;
    while(ql<=qr){
        ux=qx[ql];
        uy=qy[ql++];
        for(i=0; i<4; i++) if(!(a[ux][uy]&F[i]) and !vis[vx=ux+MX[i]][vy=uy+MY[i]]){
            vis[vx][vy]=1;
            qx[++qr]=vx;
            qy[qr]=vy;
            ans++;
        }
    }
    return ans;
}
int main(){
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    scanf("%d %d", &m, &n);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) scanf("%d", &a[i][j]);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) if(!vis[i][j]){
        ans1++;
        ans2=max(ans2, temp=fill(i, j));
        // printf("# %d %d %d\n", i, j, temp);
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(i-1 and a[i][j]&2){ //north
                // printf("# %d %d N\n", i, j);
                memset(vis, 0, sizeof(vis));
                a[i][j]^=2;
                a[i-1][j]^=8;
                temp=fill(i, j);
                if(temp>ans3 or (temp==ans3 and (j<ans4[2] or (j==ans4[2] and i>ans4[1])))){
                    ans3=temp;
                    ans4[1]=i;
                    ans4[2]=j;
                    ans4[3]='N';
                }
                a[i][j]^=2;
                a[i-1][j]^=8;
            }
            if(j<m and a[i][j]&4){
                // printf("# %d %d E\n", i, j);
                memset(vis, 0, sizeof(vis));
                a[i][j]^=4;
                a[i][j+1]^=1;
                temp=fill(i, j);
                if(temp>ans3 or (temp==ans3 and (j<ans4[2] or (j==ans4[2] and i>ans4[1])))){
                    ans3=temp;
                    ans4[1]=i;
                    ans4[2]=j;
                    ans4[3]='E';
                }
                a[i][j]^=4;
                a[i][j+1]^=1;
            }
        }
    }
    printf("%d\n%d\n%d\n%d %d %c\n", ans1, ans2, ans3, ans4[1], ans4[2], ans4[3]);
    return 0;
}
