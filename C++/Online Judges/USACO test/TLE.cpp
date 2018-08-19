/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: test
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int w[1005][1005];
int n;
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int a, b;
    int i, j, k;
    n=700;
    memset(w, 0x3f, sizeof(w));

    scanf("%d %d", &a, &b);
    w[1][2]=a;
    w[2][3]=b;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                w[i][j]=min(w[i][j], w[i][k]+w[k][j]); //Floyd
    printf("%d\n", w[1][3]);
    return 0;
}
