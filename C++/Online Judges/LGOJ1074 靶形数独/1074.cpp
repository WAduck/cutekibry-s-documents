#include <cstdio>
#include <algorithm>
using namespace std;
const int proc[10][10]={
{},
{-1, 6, 6, 6, 6, 6, 6, 6, 6, 6},
{-1, 6, 7, 7, 7, 7, 7, 7, 7, 6},
{-1, 6, 7, 8, 8, 8, 8, 8, 7, 6},
{-1, 6, 7, 8, 9, 9, 9, 8, 7, 6},
{-1, 6, 7, 8, 9, 10, 9, 8, 7, 6},
{-1, 6, 7, 8, 9, 9, 9, 8, 7, 6},
{-1, 6, 7, 8, 8, 8, 8, 8, 7, 6},
{-1, 6, 7, 7, 7, 7, 7, 7, 7, 6},
{-1, 6, 6, 6, 6, 6, 6, 6, 6, 6},
};
bool avis[10][10], bvis[10][10], cvis[10][10];
int a[10][10];
int cnt1[10];
int dfsid[10];
int ans=-1;
inline int area(int x, int y){
	return (x-1)/3*3+(y-1)/3;
}
inline bool update(int x, int y){
	if(a[x][y]){
		int z=area(x, y);
		if(avis[x][a[x][y]] or bvis[y][a[x][y]] or cvis[z][a[x][y]]) return false;
		avis[x][a[x][y]]=bvis[y][a[x][y]]=cvis[z][a[x][y]]=true;
	}
	return true;
}
void dfs(int xid, int y){
    int x=dfsid[xid];
	if(xid>9){
		int i, j, sum=0;
		for(i=1; i<=9; i++) for(j=1; j<=9; j++) sum+=a[i][j]*proc[i][j];
		ans=max(ans, sum);
		return;
	}
	if(a[x][y]){ dfs(xid+(y==9), y%9+1); return; }
	int i, z=area(x, y);
	for(i=1; i<=9; i++) if(!avis[x][i] and !bvis[y][i] and !cvis[z][i]){
		avis[x][i]=bvis[y][i]=cvis[z][i]=true;
		a[x][y]=i;
		dfs(xid+(y==9), y%9+1);
		avis[x][i]=bvis[y][i]=cvis[z][i]=false;
		a[x][y]=0;
	}
}
bool cmp(int x, int y){ return cnt1[x]>cnt1[y]; }
int main(){
	int i, j, k, x, ctr;
	for(i=1; i<=9; i++) for(j=1; j<=9; j++){
		k=area(i, j);
		scanf("%d", &a[i][j]);
		cnt1[i]+=bool(a[i][j]);
		if(!update(i, j)){
			printf("-1");
			return 0;
		}
	}
	for(i=1; i<=9; i++) dfsid[i]=i;
	sort(dfsid+1, dfsid+10, cmp);
	for(i=1; i<=9; i++) for(j=1; j<=9; j++) if(!a[i][j]){
		k=area(i, j);
		for(ctr=0, x=1; x<=9; x++) ctr+=!avis[i][x] and !bvis[j][x] and !cvis[k][x];
		if(ctr==1){
			for(x=1; avis[i][x] or bvis[j][x] or cvis[k][x]; x++);
			a[i][j]=x;
			update(i, j);
		}
	}
	dfs(1, 1);
	printf("%d", ans);
}
