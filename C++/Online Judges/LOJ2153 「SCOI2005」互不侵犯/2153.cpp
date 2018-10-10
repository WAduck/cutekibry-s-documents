#include <cstdio>
using namespace std;
typedef long long ll;
int num[1<<9];
ll f[2][100][1<<9];
int cal(int x){
	int counter=0;
	while(x){
		if(x&1 and x&2)
			return -1;
		counter+=x&1;
		x>>=1;
	}
	return counter;
}
bool judge(int x, int y){
	//if(x==y)
		//return 1;
	if(x&1 and (y&1 or y&2))
		return 0;
	while(x){
		if(x&2 and (y&1 or y&2 or y&4))
			return 0;
		x>>=1;
		y>>=1;
	}
	return 1;
}
int main(){
    int i, j, k, l, tmp;
    int counter;
    int n, m;
    ll ans;

    scanf("%d %d", &n, &m);
    for(i=0; !(i>>n); i++)
    	num[i]=cal(i);

    for(i=0; !(i>>n); i++)
    	if(~num[i])
    		f[1][num[i]][i]++;

    for(i=2; i<=n; i++){
    	for(j=0; !(j>>n); j++){
    		if(~num[j]){
    			for(k=0; !(k>>n); k++){
    				if(~num[k] and judge(j, k)){
    					for(l=num[k]; l+num[j]<=m; l++)
    						f[i&1][num[j]+l][j]+=f[!(i&1)][l][k];
					}
				}
			}
		}
		for(j=0; j<=m; j++)
			for(k=0; !(k>>n); k++)
				f[!(i&1)][j][k]=0;
	}

	ans=0;
	for(i=0; !(i>>n); i++)
		if(~num[i])
			ans+=f[n&1][m][i];
	printf("%lld", ans);
    return 0;
}
