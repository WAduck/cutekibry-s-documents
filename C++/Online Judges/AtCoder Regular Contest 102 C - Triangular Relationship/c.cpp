/*
make a=.

(a+b)%k=0
(a+c)%k=0
(b+c)%k=0

*/
#include <cstdio>
typedef long long int64;
using namespace std;
const int SQRT=450;
int64 c[SQRT+50];
int n, m, i, j, k, step;
int64 ans;
int main(){
    scanf("%d %d", &n, &m);
    if(m>=SQRT){
        if(m&1) step=m;
        else step=m>>1;
        for(i=step; i<=n; i+=step){
            for(j=step; j<=n; j+=step){
                for(k=step; k<=n; k+=step){
                    if((i+j)%m==0 and (j+k)%m==0 and (i+k)%m==0){
                        ans++;
                    }
                }
            }
        }
    }
    else{
        for(i=1; i<=n; i++) c[i%m]++;
        for(i=0; i<m; i++)
            for(j=0; j<m; j++)
                for(k=0; k<m; k++)
                    if((i+j)%m==0 and (j+k)%m==0 and (i+k)%m==0){
                        ans+=(int64)c[i]*c[j]*c[k];
                    }
    }
    printf("%lld\n", ans);
    return 0;
}
