/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: ttwo
*/
#include <cstdio>
#include <cstring>
using namespace std;
bool app[15][15][5][15][15][5];
bool map[15][15];
const int mx[]= {-1, 0, 1, 0};
const int my[]= {0, 1, 0, -1};
int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
	int i, j;
	char ch;
	int ax, ay, bx, by, af, bf, t=0;

	memset(map, 1, sizeof(map));
	for(i=1; i<=10; i++) {
		for(j=1; j<=10; j++) {
			do ch=getchar();
			while(ch<=32);
			if(ch=='F') ax=i, ay=j;
			else if(ch=='C') bx=i, by=j;
			map[i][j]=ch=='*';
		}
	}
	af=0;
	bf=0;
	while(!app[ax][ay][af][bx][by][bf] and (ax!=bx or ay!=by)) {
		app[ax][ay][af][bx][by][bf]=true;
		if(map[ax+mx[af]][ay+my[af]]) af=(af+1)&3;
		else ax+=mx[af], ay+=my[af];
		if(map[bx+mx[bf]][by+my[bf]]) bf=(bf+1)&3;
		else bx+=mx[bf], by+=my[bf];
		t++;
	}
	if(ax==bx and ay==by) printf("%d\n", t);
	else printf("0\n");
	return 0;
}
