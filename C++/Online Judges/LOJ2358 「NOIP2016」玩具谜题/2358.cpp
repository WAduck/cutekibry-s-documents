#include <cstdio>
using namespace std;
char name[100005][11];
int front[100005];
int main(){
	int i, j, k;
	int n, m;
	int tmp;
	int step;
	int p=1;

	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		scanf("%d %s", &front[i], name[i]);
	for(i=1; i<=m; i++){
		scanf("%d %d", &tmp, &step);
		if(front[p]^tmp){
			p+=step;
			if(p>n)
				p-=n;
		}
		else{
			p-=step;
			if(p<=0)
				p+=n;
		}
	}
	printf("%s", name[p]);
	return 0;
}
