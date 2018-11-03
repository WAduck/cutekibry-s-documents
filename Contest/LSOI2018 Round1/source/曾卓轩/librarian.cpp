#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105;

int n,q;
char lbr[maxn][maxn],wnt[maxn][maxn];
int len[maxn];
bool usd[maxn];

bool same(int i,int j){		//lbr[i],wnt[j]
	int len0=strlen(lbr[i]);
	if(len0!=len[j])
		return false;
	for(int p=0;p<len0;p++){
		if(lbr[i][p]!=wnt[j][p])
			return false;
	}
	return true;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",lbr[i]);
	}
	for(int j=1;j<=q;j++){
		scanf("%d",&len[j]);
		scanf("%s",&wnt[j]);
		bool found=0;
		for(int i=1;i<=n;i++){
			if(!usd[i] and same(i,j)){
				usd[i]=true;
				printf("1\n");
				found=1;
				break;
			}
		}
		if(found==0)
			printf("0\n");
	}
//	for(int i=1;i<=n;i++)
//		printf("%s\n",lbr[i]);
//	for(int i=1;i<=q;i++)
//		printf("%d %s\n",len[i],wnt[i]);
	return 0;
}
