#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int n;
inline int get(int x){
	int i;
	int ctr=0, tmp=0;
	for(i=1; i<=n; i++){
		tmp+=a[i];
		if(tmp+a[i+1]>x){
			tmp=0;
			ctr++;
		}
	}
	return ctr;
}
int main(){
	int i;
	int l=0, r=0, mid;
	int m, tmp;

	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		l=max(l, a[i]);
		r+=a[i];
	}
	a[n+1]=1e9;
	while(l<r){
		mid=(l+r)>>1;
		tmp=get(mid);
		if(tmp<=m)
			r=mid;
		else
			l=mid+1;
	}
	printf("%d", l);
	return 0;
}
