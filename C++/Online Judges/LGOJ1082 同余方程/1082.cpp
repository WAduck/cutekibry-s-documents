#include <cstdio>
using namespace std;
typedef long long int64;
int64 x, y;
void exgcd(int64 a, int64 b, int64 &x, int64 &y){
	if(!b){ x=1; y=0; }
	else{ exgcd(b, a%b, y, x); y-=a/b*x; }
}
int main(){
	int64 a, b;

	scanf("%lld %lld", &a, &b);
	exgcd(a, b, x, y);
	printf("%lld", (x+b)%b);
	return 0;
}
