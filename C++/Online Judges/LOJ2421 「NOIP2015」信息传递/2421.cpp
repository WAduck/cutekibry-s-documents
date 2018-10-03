#include <cstdio>
#include <algorithm>
using namespace std;
int w[200005];
int ctr[200005];
int stack[200005], top;
int main(){
	int i, p, size;
	int n;
	int ans=0x7fffffff;

	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &w[i]);
		ctr[w[i]]++;
	}
	for(i=1; i<=n; i++)
		if(!ctr[i])
			stack[++top]=i;

	while(top){
		ctr[w[stack[top]]]--;
		if(!ctr[w[stack[top]]])
			stack[top]=w[stack[top]];
		else
			top--;
	}

	for(i=1; i<=n; i++){
		if(ctr[i]){
			size=0;
			p=i;
			while(ctr[p]){
				ctr[p]--;
				p=w[p];
				size++;
			}
			ans=min(ans, size);
		}
	}
	printf("%d", ans);
	return 0;
}
