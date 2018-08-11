/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: crypt1
*/
#include <cstdio>
using namespace std;
bool vis[10];
bool judge(int n, int lim){
	if(n>lim)
		return false;
	while(n){
		if(!vis[n%10])
			return false;
		n/=10;
	}
	return true;
}
bool judge(int n){
	while(n){
		if(!vis[n%10])
			return false;
		n/=10;
	}
	return true;
}
int main(){
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
	int i, j;
	int n;
	int ans=0;

	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &j);
		vis[j]=true;
	}
	for(i=111; i<=999; i++){
		if(!judge(i))
			continue;
		for(j=11; j<=99; j++){
			if(!judge(j))
				continue;
			ans+=judge(i*(j%10), 999) and judge(i*(j/10), 999) and judge(i*j, 9999);
		}
	}
	printf("%d\n", ans);
    return 0;
}
