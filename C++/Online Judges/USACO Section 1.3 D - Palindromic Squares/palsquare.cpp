/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: palsquare
*/
#include <cstdio>
using namespace std;

int b;
int buf[100], top=0;

inline void output(int n){
	top=0;
	while(n){
		buf[top]=n%b;
		n/=b;
		top++;
	}
	while(top){
		top--;
		putchar( (buf[top]<10) ? (buf[top]+48) : (buf[top]+55) );
	}
}

bool judge(int n){
	top=0;
	int i;
	n*=n;
	while(n){
		buf[top]=n%b;
		n/=b;
		top++;
	}
	for(i=0; i<top/2; i++)
		if(buf[i]!=buf[top-i-1]) return false;
	return true;
}

int main(){
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
	int i;

	scanf("%d", &b);
	for(i=1; i<=300; i++)
		if(judge(i))
			output(i),putchar(' '),output(i*i),putchar('\n');
	return 0;
}
