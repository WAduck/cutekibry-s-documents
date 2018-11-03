#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,m,sum1,sum2;
int tmp,x;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		sum1+=tmp;
	}
	sum1/=n;
	int max1=0,max2=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&tmp);
		if(tmp==max1)
			continue;
		if(tmp>max1){
			max2=max1;
			max1=tmp;
		}
		else if(tmp>max2){
			max2=tmp;
		}
	}
	sum2=max2;
	scanf("%d",&x);
	double ans1=(double)sum1*2/10,ans2=(double)sum2*3/10,ans3=(double)x*5/10;
	double ans=ans1+ans2+ans3+0.5;
//	printf("%lf %lf %lf\n",ans1,ans2,ans3);
//	printf("%lf",ans);
	printf("%d\n",(int)ans);
	return 0;
}
