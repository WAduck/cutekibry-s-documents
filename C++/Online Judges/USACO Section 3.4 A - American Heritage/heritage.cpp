/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: heritage
*/
#include <cstdio>
#include <cstring>
#define $ if(0)
using namespace std;
char a[28], b[28];
int n;
void solve(int al, int ar, int bl, int br){
    if(al>ar or bl>br) return;
    $ printf("solve(%d %d %d %d)\n", al, ar, bl, br);
    int p, len;
    for(p=al; p<=ar and a[p]^b[bl]; p++);
    solve(al, p-1, bl+1, bl+1+(p-1-al));
    solve(p+1, ar, br-(ar-p-1), br);
    putchar(b[bl]);
}
int main(){
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    scanf("%s %s", a+1, b+1);
    n=strlen(a+1);
    solve(1, n, 1, n);
    putchar('\n');
    return 0;
}
