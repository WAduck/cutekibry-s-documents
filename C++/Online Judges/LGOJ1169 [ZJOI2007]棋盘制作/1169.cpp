#include <cstdio>
#include <algorithm>
using namespace std;
int a[2005][2005];
int l[2005][2005], r[2005][2005], h[2005][2005];
int i, j, n, m;
int sqans, reans;
inline int pow2(int x){ return x*x;}
int main(){
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			scanf("%d", &a[i][j]);
	for(i=1; i<=n; i++){
	    l[i][1]=r[i][m]=0;
	    for(j=2; j<=m; j++) l[i][j]=(a[i][j]^a[i][j-1])?(l[i][j-1]+1):0;
	    for(j=m-1; j; j--) r[i][j]=(a[i][j]^a[i][j+1])?(r[i][j+1]+1):0;
	}
	for(i=1; i<=m; i++) h[1][i]=1;
    for(i=2; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]^a[i-1][j])
                h[i][j]=h[i-1][j]+1,
                l[i][j]=min(l[i][j], l[i-1][j]),
                r[i][j]=min(r[i][j], r[i-1][j]);
            else
                h[i][j]=1;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			sqans=max(sqans, pow2(min(h[i][j], r[i][j]+l[i][j]+1))),
			reans=max(reans, h[i][j]*(r[i][j]+l[i][j]+1));
	printf("%d\n%d\n", sqans, reans);
	return 0;
}
