#include <cstdio>
#define trans(a)	((a>=10)?(a+55):(a+48))
using namespace std;
int s[20], stop=0;
int main(){
	int n, r;

	scanf("%d %d", &n, &r);
	printf("%d=", n);
	while(n){
		stop++;
		s[stop]=n%r;
		n/=r;
		if(s[stop]<0){
			s[stop]-=r;
			n++;
		}
	}
	if(!stop)
		putchar('0');
	while(stop){
		putchar(trans(s[stop]));
		stop--;
	}
	printf("(base%d)", r);
	return 0;
} 
