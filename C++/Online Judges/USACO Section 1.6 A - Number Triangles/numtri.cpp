/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: numtri
*/
#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int tower[1001][1001];

int main(){
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
	int i, j;
	int r;

	scanf("%d", &r);
	for(i=1; i<=r; i++)
		for(j=1; j<=i; j++)
			scanf("%d", &tower[i][j]);

	for(i=r-1; i>=1; i--)
		for(j=1; j<=i; j++)
			tower[i][j]+=max(tower[i+1][j],tower[i+1][j+1]);

	printf("%d\n", tower[1][1]);
	return 0;
}
