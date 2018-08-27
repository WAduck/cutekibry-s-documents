/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: inflate
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[10005];
int main(){
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
	int i, j;
	int n, m;
	int p, t;

	scanf("%d %d", &m, &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &p, &t);
		while(t<=m){
			for(j=m; j>=t; j--)
				dp[j]=max(dp[j], dp[j-t]+p);
			t<<=1;
			p<<=1;
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}
