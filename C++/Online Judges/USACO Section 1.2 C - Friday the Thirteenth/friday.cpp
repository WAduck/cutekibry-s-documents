/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: friday
*/
#include <cstdio>
using namespace std;
const int days[]={-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int count[13];
int main(){
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
	int i;
	int y=1900, p=0;
	int n;

	scanf("%d", &n);
	while(n--){
		for(i=1; i<=12; i++){
			count[p]++;
			if(i==2)
				p+=days[2]+(!(y%4) and y%100 or !(y%400));
			else
				p+=days[i];
			p%=7;
		}
		y++;
	}
	for(i=0; i<6; i++)
		printf("%d ", count[i]);
    printf("%d\n", count[6]);
	return 0;
}
