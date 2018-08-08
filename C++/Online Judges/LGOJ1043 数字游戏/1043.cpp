#include <cstdio>
#include <algorithm>
using namespace std;
int minf[11][55], maxf[11][55];
int s[55];
int a[55];
int main(){
	int i, j, k;
	int n, m;
	int x;
	int tmp;
	int minans=0x7fffffff, maxans=0;

	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);

	for(x=1; x<=n; x++){
		tmp=a[1];
		for(i=1; i<n; i++)
			a[i]=a[i+1];
		a[n]=tmp;

		s[0]=0;
		for(i=1; i<=n; i++){
			s[i]=s[i-1]+a[i];
			minf[1][i]=maxf[1][i]=(s[i]+500000)%10;
		}

		for(i=2; i<=m; i++){
			minf[i][i]=maxf[i][i]=(s[i]+500000)%10;
			for(j=i+1; j<=n; j++){
				minf[i][j]=0x7fffffff;
				maxf[i][j]=0;
				for(k=i-1; k<j; k++){
					minf[i][j]=min(minf[i][j], minf[i-1][k]*((s[j]-s[k]+500000)%10));
					maxf[i][j]=max(maxf[i][j], maxf[i-1][k]*((s[j]-s[k]+500000)%10));
				}
			}
		}

		minans=min(minans, minf[m][n]);
		maxans=max(maxans, maxf[m][n]);
	}

	printf("%d\n%d", minans, maxans);
	return 0;
}
