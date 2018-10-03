#include <cstdio>
using namespace std;
int cube[42][42];
int main(){
	int i, j;
	int x, y;
	int n;

	scanf("%d", &n);

	for(i=0; i<=n+1; i++)
		cube[i][0]=cube[0][i]=cube[i][n+1]=cube[n+1][i]=-1;

	x=1, y=(n>>1)+1;
	cube[x][y]=1;
	for(i=2; i<=n*n; i++){
		if(cube[x-1][y+1]){
			if(x==1 and y==n)
				x++;
			else if(x==1)
				x=n, y++;
			else if(y==n)
				y=1, x--;
			else
				x++;
		}
		else
			x--, y++;
		cube[x][y]=i;
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d ", cube[i][j]);
		}
		printf("\n");
	}
	return 0;
}
