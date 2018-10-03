#include <cstdio>
#include <algorithm>
#define DEBUG 1
#define $ if(DEBUG)
using namespace std;
typedef long long int64;
const int SCP=682*999*15;
int q[3][SCP], ql[3], qr[3];
double p;
int n, m, qq, u, v, x, t;
int i, j;
int main(){
    scanf("%d %d %d %d %d %d", &n, &m, &qq, &u, &v, &t);
    p=double(u)/v;
    for(i=1; i<=n; i++)
        scanf("%d", &q[0][i]);
    sort(q[0]+1, q[0]+1+n);
    for(i=1, j=n; i<j; i++, j--) swap(q[0][i], q[0][j]);
    ql[0]=ql[1]=ql[2]=qr[0]=qr[1]=qr[2]=1;
    qr[0]=n+1;
    for(i=1; i<=m; i++){
        // ${
        //     printf("\n# ");
        //     for(j=ql[0]; j<qr[0]; j++) printf("%d ", q[0][j]); printf("\n# ");
        //     for(j=ql[1]; j<qr[1]; j++) printf("%d ", q[1][j]); printf("\n# ");
        //     for(j=ql[2]; j<qr[2]; j++) printf("%d ", q[2][j]); printf("\n");
        // }
        x=-1e9;
        if(ql[0]^qr[0]) x=max(x, q[0][ql[0]]);
        if(ql[1]^qr[1]) x=max(x, q[1][ql[1]]);
        if(ql[2]^qr[2]) x=max(x, q[2][ql[2]]);
        if(i%t==0) printf("%d ", x+(i-1)*qq);
        if(ql[0]^qr[0] and q[0][ql[0]]==x) ql[0]++;
        else if(ql[1]^qr[1] and q[1][ql[1]]==x) ql[1]++;
        else ql[2]++;
        x+=(i-1)*qq;
        q[1][qr[1]++]=(int64)x*u/v-i*qq;
        q[2][qr[2]++]=x-(int64)x*u/v-i*qq;
    }
    // ${
    //     printf("\n# ");
    //     for(j=ql[0]; j<qr[0]; j++) printf("%d ", q[0][j]); printf("\n# ");
    //     for(j=ql[1]; j<qr[1]; j++) printf("%d ", q[1][j]); printf("\n# ");
    //     for(j=ql[2]; j<qr[2]; j++) printf("%d ", q[2][j]); printf("\n");
    // }
    putchar('\n');
    i=1;
    while(ql[0]^qr[0] or ql[1]^qr[1] or ql[2]^qr[2]){
        x=-1e9;
        if(ql[0]^qr[0]) x=max(x, q[0][ql[0]]);
        if(ql[1]^qr[1]) x=max(x, q[1][ql[1]]);
        if(ql[2]^qr[2]) x=max(x, q[2][ql[2]]);
        if(i%t==0) printf("%d ", x+m*qq);
        i++;
        if(ql[0]^qr[0] and q[0][ql[0]]==x) ql[0]++;
        else if(ql[1]^qr[1] and q[1][ql[1]]==x) ql[1]++;
        else ql[2]++;
        // ${
        //     printf("\n# ");
        //     for(j=ql[0]; j<qr[0]; j++) printf("%d ", q[0][j]); printf("\n# ");
        //     for(j=ql[1]; j<qr[1]; j++) printf("%d ", q[1][j]); printf("\n# ");
        //     for(j=ql[2]; j<qr[2]; j++) printf("%d ", q[2][j]); printf("\n");
        //     if(n++>=10) return 0;
        // }

    }
    return 0;
}
