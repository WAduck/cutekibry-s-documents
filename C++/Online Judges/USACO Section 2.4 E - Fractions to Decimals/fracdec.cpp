/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: fracdec
*/
#include <cstdio>
#include <cstring>
using namespace std;
int p[1000006];
char s[1000006];
char res[2000006];
int top;
int main(){
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
	int i, j;
	int a, b;
	char temp;

	scanf("%d %d", &a, &b);
	sprintf(res, "%d.", a/b);
	if(!(a%b)){
		printf("%d.0\n", a/b);
		return 0;
	}
	a=a%b*10;
	while(1){
		if(p[a]){
			p[a]--;
			temp=s[p[a]];
			s[p[a]]=0;
			sprintf(res+strlen(res), "%s", s);
			if(!a)
				break;
			s[p[a]]=temp;
			sprintf(res+strlen(res), "(%s)", s+p[a]);
			break;
		}
		p[a]=top+1;
		s[top]=a/b+48;
		top++;
		a=a%b*10;
	}
	j=0;
	for(i=0; res[i]; i++){
		putchar(res[i]);
		j++;
		if(!(j^76)){
			j=0;
			putchar('\n');
		}
	}
    if(j^76) putchar('\n');
	return 0;
}
