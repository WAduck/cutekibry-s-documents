#include <cstdio>
using namespace std;
char num[30];
int main(){
	int i, j;
	int s, t, w;
	int tmp=5;

	scanf("%d %d %d", &s, &t, &w);
	scanf("%s", num+1);
	while(tmp){
		i=w;
		while(i){
			if(num[i]-96>=t){
				i--;
				continue;
			}
			num[i]++;
			for(j=i+1; j<=w; j++){
				num[j]=num[j-1]+1;
				if(num[j]-96>t)
					break;
			}
			if(j<=w){
				i--;
				continue;
			}
			else
				break;
		}
		if(!i)
			break;
		printf("%s\n", num+1);
		tmp--;
	}
	return 0;
} 
