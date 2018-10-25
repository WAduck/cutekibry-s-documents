#include <cstdio>
using namespace std;
const int SCP=682*999*2;
int a[SCP], m, i, j, opt, x, y;
int main(){
    freopen("2302.in", "r", stdin);
    freopen("brust.out", "w", stdout);

    scanf("%d %d %d %d", &m, &i, &i, &i);
    for(i=1; i<=m; i++){
        scanf("%d %d", &opt, &x);
        if(opt==1){
            scanf("%d", &y);
            if(x<0){
                x=-x;
                for(j=0; x>>j; j++){
                    a[y+j]-=x>>j&1;
                    if(a[y+j]<0) a[y+j]+=2, a[y+j+1]--;
                }
                while(a[y+j]<0) a[y+j]+=2, a[y+j+1]--, j++;
            }
            else
                for(j=0; x>>j; j++){
                    a[y+j]+=x>>j&1;
                    if(a[y+j]>1) a[y+j]-=2, a[y+j+1]++;
                }
                while(a[y+j]>1) a[y+j]-=2, a[y+j+1]++, j++;
        }
        else
            printf("%d\n", a[x]);
    }
    return 0;
}
