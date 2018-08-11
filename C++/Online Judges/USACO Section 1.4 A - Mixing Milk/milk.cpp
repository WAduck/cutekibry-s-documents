/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct Cow{
	int p;
	int a;
	bool operator < (const Cow b){
		return p < b.p;
	}
};

Cow cow[5000];

int main(){
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
	int i, j;
	int n, m;

	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++)
		scanf("%d %d", &cow[i].p, &cow[i].a);

	sort(cow, cow+m);

	int cost=0;
    for(i=0; n>cow[i].a; i++){
        n-=cow[i].a;
        cost+=cow[i].a*cow[i].p;
    }
    cost+=n*cow[i].p;
    printf("%d\n", cost);
    return 0;
}
