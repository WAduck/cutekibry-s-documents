#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int MAXN=2001;
int c[2005][2005], sum[2005][2005];
int main(){
    int i, j;
    int t, k, n, m;

    scanf("%d %d", &t, &k);
    for(i=0; i<=MAXN; i++) c[i][0]=1;
    for(i=1; i<=MAXN; i++)
    	for(j=1; j<=i; j++)
    		c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
    for(i=1; i<=MAXN; i++)
    	for(j=1; j<=MAXN; j++)
    		sum[i][j]=(!c[i][j] and j<=i)+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

	while(t--){
        scanf("%d %d", &n, &m);
        printf("%d\n", sum[n][m]);
    }
}
