#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[66][3300];
int v[66][5], p[66][5];
int n, m;
void dp(int no, int v, int p){
    int i;
    for(i=n; i>=v; i--)
        f[no][i]=max(f[no][i], f[no-1][i-v]+p);
}
int main(){
    int i, j, x, y, z;

    scanf("%d %d", &n, &m);
    n/=10;
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &x, &y, &z);
        y=x*y;
        x/=10;
        if(z){
            if(p[z][2]){
                v[z][3]=x;
                p[z][3]=y;
            }
            else{
                v[z][2]=x;
                p[z][2]=y;
            }
        }
        else{
            v[i][1]=x;
            p[i][1]=y;
        }
    }
    for(i=1; i<=m; i++){
        memcpy(f[i], f[i-1], sizeof(f[i]));
        if(p[i][1])
            dp(i, v[i][1], p[i][1]);
        if(p[i][2])
            dp(i, v[i][1]+v[i][2], p[i][1]+p[i][2]);
        if(p[i][3]){
            dp(i, v[i][1]+v[i][3], p[i][1]+p[i][3]);
            dp(i, v[i][1]+v[i][2]+v[i][3], p[i][1]+p[i][2]+p[i][3]);
        }
        //printf("#%d %d\n", i, f[i][n]);
    }
    printf("%d", f[m][n]);
    return 0;
}
