#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=10000005;
bool vis[256];
char ts[256];
int n, step, ans;
char x[256], y[256];
bool err;
int str2int(char *s){
	int n=0;
	while((*s)>='0' and (*s)<='9'){
		n=(n<<3)+(n<<1)+((*s)&15);
		s++;
	}
	return n;
}
bool make(bool isok, int dep, bool enter){
	char ch;
	int x, y;

	if(step>n){ err=true; return false; }
	scanf(" %c", &ch);
	if(isok) ans=max(ans, dep);
	if(ch=='E'){
		if(enter) err=true;
		return false;
	}
	scanf(" %c %s", &ch, ts+1);
	if(vis[ch]) err=true;
	vis[ch]=true;
	if(ts[1]^'n') x=str2int(ts+1);
	else x=N;
	scanf("%s", ts+1);
	if(ts[1]^'n') y=str2int(ts+1);
	else y=N;
	do step++; while(make(isok and (x<=y), dep+(x^N and y==N), false));
	vis[ch]=false;
	return true;
}
int main(){
	int t, i, a;

	scanf("%d", &t);
	while(t--){
		scanf("%d %s", &n, ts+1);
		if(ts[3]==1) a=0;
		else a=str2int(ts+5);
		ans=err=0;
		step=0;
		memset(vis, 0, sizeof(vis));
		while(step<n){
			step++;
			make(true, 0, true);
		}
		if(err) printf("ERR\n");
		else if(a^ans) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
/*
3
2 O(n^68)
E
E
3 O(n^1)
F i 1 n
E
E
8 O(n^2)
F i 2 n
F j 88 n
F k n 50
F l 50 n
E
E
E
E
*/
