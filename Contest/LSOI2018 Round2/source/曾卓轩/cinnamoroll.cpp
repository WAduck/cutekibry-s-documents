#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000005;
const int mod=1e9+7;

long long n,m;

long long gcd(long long a,long long b){
	if(a==b)
		return a;
	if(a>b)	swap(a,b);
	return gcd(a,b-a);
}

long long ksm(long long x,long long k){
	long long ans=1;
	while(k){
		if(k%2==1)
			ans=ans*x%mod;
		k/=2;
		x=x*x%mod;
	}
	return ans;
}

int main(){
	freopen("cinnamoroll.in","r",stdin);
	freopen("cinnamoroll.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	if(m==1){
		long long x;
		scanf("%lld",&x);
		long long tmp=n/x;
		n-=tmp;
	}	
	else if(m==2){
		long long x1,x2;
		scanf("%lld %lld",&x1,&x2);
		long long g=x1*x2/gcd(x1,x2);
		long long tmp1=n/x1,tmp2=n/x2,tmp3=n/g;
		n=n-tmp1-tmp2+tmp3;
	}
	n-=2;
	printf("%lld\n",ksm(2,n));
	return 0;
}
