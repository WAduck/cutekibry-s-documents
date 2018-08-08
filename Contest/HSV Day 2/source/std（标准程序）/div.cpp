#include <cstdio>
#include <cstring>
using namespace std;
char s[105];
int t, a, b;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %s", &a, s+1);
		printf("%d/%s=", a, s+1);
        if(strlen(s+1)>=8) printf("0.000\n");
		else{
			sscanf(s+1, "%d", &b);
			printf("%.3lf\n", (double)a/b);
		}
	}
	return 0;
}
