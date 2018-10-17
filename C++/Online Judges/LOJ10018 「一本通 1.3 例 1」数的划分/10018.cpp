#include <cstdio>
using namespace std;

int a[7]={1};
int n, k;
int ans=0;

void dfs(int p, int sum){
	int i;
	if(p==k){
		ans++;
		return;
	}
	for(i=a[p-1]; i<=n; i++){
		a[p]=i;
		sum+=a[p];
		if(n-sum>=i)
			dfs(p+1, sum);
		else
			break;
		sum-=a[p];
	}
}

int main(){
	scanf("%d %d", &n, &k);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}
