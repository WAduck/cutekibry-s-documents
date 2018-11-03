#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,q,maxq,a[maxn],b[maxn],ans[maxn],minans[maxn];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&b[i]);
		maxq=max(maxq,b[i]);
	}
	minans[0]=1<<29;
	for(int i=1;i<=maxq;i++){
		int tmp=0;
		for(int j=1;j<=n;j++)
			tmp+=(a[j]+i)*(a[j]+i);
		ans[i]=tmp/i;
		minans[i]=min(minans[i-1],ans[i]);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",minans[b[i]]);
	return 0;
}
