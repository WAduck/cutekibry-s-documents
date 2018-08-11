/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: beads
*/
#include <cstdio>
#include <algorithm>
using namespace std;
char s[400];
int rfront[400], bfront[400], rback[400], bback[400];
int main(){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
	int i, n;
	int ans=0;

	scanf("%d", &n);
	scanf("%s", s+1);
	if(s[1]^'b'){
		rfront[1]=1;
		for(i=n; i>1 and s[i]^'b'; i--)
			rfront[1]++;
	}
	if(s[1]^'r'){
		bfront[1]=1;
		for(i=n; i>1 and s[i]^'r'; i--)
			bfront[1]++;
	}
	if(s[n]^'b'){
		rback[n]=1;
		for(i=1; i<n and s[i]^'b'; i++)
			rback[n]++;
	}
	if(s[n]^'r'){
		bback[n]=1;
		for(i=1; i<n and s[i]^'r'; i++)
			bback[n]++;
	}

	for(i=2; i<=n; i++){
		rfront[i]=(s[i]^'b')?(rfront[i-1]+1):(0);
		bfront[i]=(s[i]^'r')?(bfront[i-1]+1):(0);
	}
	for(i=n-1; i>=1; i--){
		rback[i]=(s[i]^'b')?(rback[i+1]+1):(0);
		bback[i]=(s[i]^'r')?(bback[i+1]+1):(0);
	}

	rfront[0]=rfront[n];
	bfront[0]=bfront[n];
	for(i=1; i<=n; i++)
		ans=max(ans, max(rfront[i-1], bfront[i-1])+max(rback[i], bback[i]));
	printf("%d\n", min(ans,n));
	return 0;
}
