/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: fact4
*/
#include <cstdio>
using namespace std;
int main(){
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
	register int i;
	long long f=1;
	int n;

	scanf("%d", &n);
	for(i=2; i<=n; i++){
		f*=i;
		while(!(f%10))
			f/=10;
		f%=10000000;
	}
	printf("%lld\n", f%10);
	return 0;
}
