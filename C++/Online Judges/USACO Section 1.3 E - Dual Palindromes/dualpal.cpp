/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: dualpal
*/
#include <cstdio>
using namespace std;
int a[100], top;
bool judge(int n){
	int i, j;
	int ans=0;
	int tn;

	for(i=10; i>=2; i--){
		tn=n;
		top=0;
		while(tn){
			a[++top]=tn%i;
			tn/=i;
		}
		for(j=1; j<=(top>>1); j++)
			if(a[j]^a[top-j+1])
				break;
		if(j>(top>>1))
			ans++;
		if(ans>>1)
			return true;
	}
	return false;
}
int main(){
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
	int n;
	int s;

	scanf("%d %d", &n, &s);
	while(n){
		s++;
		if(judge(s)){
			printf("%d\n", s);
			n--;
		}
	}
	return 0;
}
