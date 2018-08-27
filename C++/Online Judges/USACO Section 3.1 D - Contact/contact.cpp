/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: contact
*/
#include <cstdio>
#include <cstring>
#define $ if(0)
using namespace std;
const int SCP=682*999/3;
int i, j, k, n, m, x, a, b;
int c[15][1<<15];
bool cc[SCP];
char s[SCP];
bool buff[25];
int flag;
inline void writebit(int x, int len){
    int i;
    for(i=len; i; i--) buff[i]=x&1, x>>=1;
    for(i=1; i<=len; i++) putchar(buff[i]|48);
}
int main(){
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    scanf("%d %d %d", &a, &b, &m);
    while(~scanf("%s", s+n+1)) n=strlen(s+1);
    for(i=a; i<=b and i<=n; i++){
        x=0;
        for(j=1; j<i; j++) x=(x<<1)|(s[j]&1);
        j=1;
        for(k=i; k<=n; j++, k++){
            x=(x<<1)|(s[k]&1);
            x&=(1<<i)-1;
            c[i][x]++;
            $ printf("%d %d %d%d\n", j, k, x>>1, x&1);
        }
        for(j=0; !(j>>i); j++) cc[c[i][j]]=1;
    }
    for(i=n; i and m; i--) if(cc[i]){
        m--;
        printf("%d", i);
        flag=0;
        for(j=a; j<=b; j++){
            for(k=0; !(k>>j); k++) if(c[j][k]==i){
                if(flag%6==0) putchar('\n');
                else if(flag) putchar(' ');
                writebit(k, j); flag++;
            }
        }
        putchar('\n');
    }
    return 0;
}
