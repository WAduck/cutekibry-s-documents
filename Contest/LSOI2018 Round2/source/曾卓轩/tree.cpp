#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100005;

char s[maxn];int len;
char s0[10]="freopen";
int ans;

void read(){
	char c;
	int i=0;
	while((scanf("%c",&c))==1){
//		if(c=='f' or c=='r' or c=='e' or c=='o' or c=='p' or c=='n')
			s[i++]=c;
	}
	len=strlen(s);
}

void solve(){
	int k=0;
	for(int i=0;i<len;i++){
		if(s[i]!=s0[k])	k=0;
		if(s[i]==s0[k])	k++;
		if(k==7)	ans++;
	}
	printf("%d\n",ans);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read();
	solve();
	return 0;
}
