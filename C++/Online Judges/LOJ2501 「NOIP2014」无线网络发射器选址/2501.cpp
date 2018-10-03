#include <cstdio>
using namespace std;
int px[25], py[25], pk[25];
int d;
inline int judge(int a, int b, int c){
	if(px[c]>=a-d and px[c]<=a+d and py[c]>=b-d and py[c]<=b+d)
		return pk[c];
	return 0;
}
int main(){
	int i, j, k;
	int n;
	int ans=0, maxn=0;
	int tmp;

	scanf("%d", &d);
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%d %d %d", &px[i], &py[i], &pk[i]);

	for(i=0; i<=128; i++){
		for(j=0; j<=128; j++){
			tmp=0;
			for(k=1; k<=n; k++)
				tmp+=judge(i, j, k);
			if(tmp>maxn){
				maxn=tmp;
				ans=1;
			}
			else if(tmp==maxn)
				ans++;
		}
	}

	printf("%d %d", ans, maxn);
	return 0;
}
