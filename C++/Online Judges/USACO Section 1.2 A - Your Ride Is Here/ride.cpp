/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: ride
*/
#include <cstdio>
using namespace std;

char s1[7];
char s2[7];

int main(){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
	int i;
	int n1=1, n2=1;

	scanf("%s %s", s1, s2);
	for(i=0; s1[i]>0; i++)
		n1*=s1[i]-64;
	for(i=0; s2[i]>0; i++)
		n2*=s2[i]-64;

	if(n1%47==n2%47)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}
