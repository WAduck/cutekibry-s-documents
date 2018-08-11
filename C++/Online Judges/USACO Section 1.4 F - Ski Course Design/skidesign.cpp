/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: skidesign
*/
#include <cstdio>
#include <algorithm>
#define pow2(a) (a)*(a)
using namespace std;
int a[1005];
int main(){
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
	int i, j, k;
	int maxn=0, minn=0x7fffffff;
	int n;
	unsigned long long ans=0xffffffffffffffff;
	unsigned long long temp;

	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		maxn=max(maxn, a[i]);
		minn=min(minn, a[i]);
	}

	for(i=(minn+maxn)>>1; i<=maxn; i++){
		temp=0;
		for(j=1; j<=n; j++){
			if(a[j]<i)
				temp+=pow2(i-a[j]);
			else if(a[j]>i+17)
				temp+=pow2(a[j]-i-17);
			if(temp>ans)
				break;
		}
		if(j>n)
			ans=temp;
		else
			break;
	}
	for(i=(minn+maxn)>>1; i>=minn; i--){
		temp=0;
		for(j=1; j<=n; j++){
			if(a[j]<i)
				temp+=pow2(i-a[j]);
			else if(a[j]>i+17)
				temp+=pow2(a[j]-i-17);
			if(temp>ans)
				break;
		}
		if(j>n)
			ans=temp;
		else
			break;
	}
	printf("%llu\n", ans);
	return 0;
}
