/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: sprime
*/
#include <cstdio>
#include <cmath>
using namespace std;
int n, a[9][2];
bool isprime(int n){
	int i, end=sqrt(n);
	for(i=2; i<=end; i++)
		if(!(n%i)) return 0;
	return (n!=1);
}

void dfs(int p, int sum){
	int i;
	if(p>n){
		printf("%d\n", sum);
		return;
	}
	for(i=1; i<=9; i++){
		if(isprime(sum*10+i)){
			dfs(p+1, sum*10+i);
		}
	}
}

int main(){
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
	scanf("%d", &n);
	dfs(1, 0);
	return 0;
}
