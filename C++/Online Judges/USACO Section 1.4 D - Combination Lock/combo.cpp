/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: combo
*/
#include <cstdio>
using namespace std;
bool vis[101][101][101];
int main(){
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
	int n;
	int i, j, k;
	int a, b, c;
	int ans=0;

	scanf("%d", &n);
	scanf("%d %d %d", &a, &b, &c);
	a=(a-3+n)%n;
	b=(b-3+n)%n;
	c=(c-3+n)%n;
	for(i=1; i<=5; i++){
		for(j=1; j<=5; j++){
			for(k=1; k<=5; k++){
				if(!vis[(a+i)%n][(b+j)%n][(c+k)%n]){
					ans++;
					vis[(a+i)%n][(b+j)%n][(c+k)%n]=true;
				}
			}
		}
	}
	scanf("%d %d %d", &a, &b, &c);
	a=(a-3+n)%n;
	b=(b-3+n)%n;
	c=(c-3+n)%n;
	for(i=1; i<=5; i++){
		for(j=1; j<=5; j++){
			for(k=1; k<=5; k++){
				if(!vis[(a+i)%n][(b+j)%n][(c+k)%n]){
					ans++;
					vis[(a+i)%n][(b+j)%n][(c+k)%n]=true;
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}
