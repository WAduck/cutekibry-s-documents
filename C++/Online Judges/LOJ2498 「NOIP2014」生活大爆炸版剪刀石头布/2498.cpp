#include <cstdio>
using namespace std;
const int match[5][5]={	{1,0,2,2,0},
						{2,1,0,2,0},
						{0,2,1,0,2},
						{0,0,2,1,2},
						{2,2,0,0,1} };
int a[205], b[205];
int main(){
	int i, j, k;
	int n, na, nb;
	int tota=0, totb=0;

	scanf("%d %d %d", &n, &na, &nb);
	for(i=1; i<=na; i++)
		scanf("%d", &a[i]);
	for(i=1; i<=nb; i++)
		scanf("%d", &b[i]);
	i=1, j=1;
	while(n){
		if(match[a[i]][b[j]]==0)
			totb++;
		else if(match[a[i]][b[j]]==2)
			tota++;
		i++, j++;
		if(i>na)
			i-=na;
		if(j>nb)
			j-=nb;
		n--;
	}
	printf("%d %d", tota, totb);
	return 0;
} 
