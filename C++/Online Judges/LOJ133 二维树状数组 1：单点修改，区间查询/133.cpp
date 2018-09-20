#include <cstdio>
using namespace std;
const int SCP=(1<<12)|50;
int cc[SCP][SCP];
int n, m, a, b, c, d, x, y, k, opt;
inline int lowbit(int x){ return x&-x; }
inline void update(int x, int y, int k){
    int i, j;
    for(i=x; i<=n; i+=lowbit(i))
        for(j=y; j<=m; j+=lowbit(j))
            cc[i][j]+=k;
}
inline int query(int x, int y){
    int i, j;
    int res=0;
    for(i=x; i; i^=lowbit(i))
        for(j=y; j; j^=lowbit(j))
            res+=cc[i][j];
    return res;
}
int main(){
    scanf("%d %d", &n, &m);
    while(~scanf("%d", &opt)){
        if(opt==1){
            scanf("%d %d %d", &x, &y, &k);
            update(x, y, k);
        }
        else{
            scanf("%d %d %d %d", &a, &b, &c, &d);
            printf("%d\n", query(c, d)-query(a-1, d)-query(c, b-1)+query(a-1, b-1));
        }
    }
    return 0;
}
