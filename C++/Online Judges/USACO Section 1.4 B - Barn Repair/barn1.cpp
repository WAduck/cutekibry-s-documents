/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: barn1
*/
#include <cstdio>
using namespace std;
int app[505];
int a[205];
int main(){
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
	int i, j;
	int m, s, c;
	int ans=0;

	scanf("%d %d %d", &m, &s, &c);
	for(i=1; i<=c; i++){
		scanf("%d", &j);
		ans+=!a[j];
		a[j]=true;
	}
	j=-250;
	for(i=1; i<=s; i++){
		if(a[i]){
			app[i-j-1]++;
			j=i;
		}
	}

	for(i=0; c-app[i]>m and i<=s; i++){
		ans+=app[i]*i;
		c-=app[i];
	}
	ans+=(c-m)*i;
	printf("%d\n", ans);
	return 0;
}
