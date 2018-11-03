#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;

struct node{
	int t,p;
}x[maxn];
int n1,n2,m;
int cost;

bool cmp(node a,node b){
	return a.p<=b.p;
}

int main(){
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	scanf("%d %d %d",&m,&n1,&n2);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&x[i].t,&x[i].p);
	sort(x,x+m+1,cmp);
	int tmp=0;
	for(int i=1;i<=m;i++){
		if(x[i].t==1 and n1){
			n1--;
			cost+=x[i].p;
		}
		else if(x[i].t==2 and n2){
			n2--;
			cost+=x[i].p;
		}
		else if(x[i].t==3){
			tmp++;
			cost+=x[i].p;
		}
		if(n1+n2==tmp)
			break;
	}
	printf("%d\n",cost);
	return 0;
}
