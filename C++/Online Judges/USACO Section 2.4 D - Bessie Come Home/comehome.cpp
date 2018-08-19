/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: comehome
*/
#include <cstdio>
#include <algorithm>
#define get(ch) (ch>='a')?(ch-'a'+26):(ch-'A')
using namespace std;
const int INF=(~(1<<31))>>1;
int w[60][60];
int main(){
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
	int i, j, k;
	int n;
	char a, b; int c;

	for(i=0; i<60; i++)
		for(j=0; j<60; j++)
			w[i][j]=INF;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf(" %c %c %d", &a, &b, &c);
		w[get(b)][get(a)]=w[get(a)][get(b)]=min(c, w[get(a)][get(b)]);
	}

	for(k=0; k<52; k++)
		for(i=0; i<52; i++)
			for(j=0; j<52; j++)
				w[i][j]=min(w[i][j], w[i][k]+w[k][j]);

	k=0;
	for(i=1; i<25; i++)
		if(w[k][25]>w[i][25])
			k=i;
	printf("%c %d\n", k+'A', w[k][25]);
	return 0;
}
