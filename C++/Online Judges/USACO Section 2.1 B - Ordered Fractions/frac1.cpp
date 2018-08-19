/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: frac1
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Num{ int a, b; };
bool cmp(Num a, Num b){ return 1.0*a.a/a.b < 1.0*b.a/b.b; }
Num ans[50000];
int top=0;

bool isprime(int a, int b){
	if(a==0) return b==1;
	int i;
	for(i=2; i<=min(a,b); i++)
		if(!(a%i) and !(b%i))
			return false;
	return true;
}
int main(){
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
	int i, j;
	int n;

	scanf("%d", &n);
	for(i=0; i<=n; i++){
		for(j=i+!i; j<=n; j++){
			if(isprime(i, j)){
				ans[top].a=i;
				ans[top].b=j;
				top++;
			}
		}
	}
	sort(ans, ans+top, cmp);
	for(i=0; i<top; i++){
		printf("%d/%d\n", ans[i].a, ans[i].b);
	}
	return 0;
}
