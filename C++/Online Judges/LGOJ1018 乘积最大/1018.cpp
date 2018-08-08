#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct hugeint{
    int a[1005];
    int len;
    hugeint operator = (hugeint b){
        len=b.len;
        memcpy(a, b.a, sizeof(b.a));
    }
    hugeint operator * (hugeint b){
        hugeint ans;
        memset(ans.a, 0, sizeof(ans.a));
        ans.len=len+b.len;
        int i, j;
        for(i=1; i<=len; i++) for(j=1; j<=b.len; j++) ans.a[i+j-1]+=a[i]*b.a[j];
        for(i=1; i<=ans.len; i++){ ans.a[i+1]+=ans.a[i]/10; ans.a[i]%=10; }
        while(!ans.a[ans.len] and ans.len>1) ans.len--;
        return ans;
    }
    hugeint operator = (int b){
        len=0;
        while(b){
            a[++len]=b%10;
            b/=10;
        }
        if(!len) a[1]=0, len=1;
        return *this;
    }

    bool operator < (hugeint b){
        if(len^b.len) return len<b.len;
        for(int i=len; i; i--)
            if(a[i]^b.a[i]) return a[i]<b.a[i];
        return false;
    }
};
inline void write(hugeint x){
    for(int i=x.len; i; i--) putchar(x.a[i]+48);
}
hugeint huge(int x){
    hugeint y;
    y=x;
    return y;
}
char s[50];
hugeint f[50][8];
hugeint trans(int begin, int end){
	hugeint temp;
	temp=0;
	while(begin<=end){
		temp=temp*huge(10);
		temp.a[1]=(s[begin]-48);
		begin++;
	}
	return temp;
}
int main(){
	int i, j, k;
	int n, m;
	hugeint temp;

	scanf("%d %d", &n, &m);
	scanf("%s", s+1);

	for(i=1; i<=n; i++) for(j=1; j<=m; j++) f[i][j]=0;

	for(i=1; i<=n; i++){
		f[i][0]=f[i-1][0]*huge(10);
		f[i][0].a[1]=s[i]-48;
	}

	for(j=1; j<=m; j++){
		for(i=j; i<=n; i++){
			for(k=1; k<i; k++){
			    temp=f[k][j-1]*trans(k+1, i);
				if(f[i][j]<temp)
				    f[i][j]=temp;

			}
		}
	}
	write(f[n][m]);
	return 0;
}
