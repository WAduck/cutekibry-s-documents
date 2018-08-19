/*
ID: TsukXmaru Oshawott
LANG: C++
TASK: preface
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
const char *A[]={" ", "I ", "II ", "III ", "IV ", "V ", "VI ", "VII ", "VIII ", "IX "};
const char *B[]={" ", "X ", "XX ", "XXX ", "XL ", "L ", "LX ", "LXX ", "LXXX ", "XC "};
const char *C[]={" ", "C ", "CC ", "CCC ", "CD ", "D ", "DC ", "DCC ", "DCCC ", "CM "};
const char *D[]={" ", "M ", "MM ", "MMM "};
const char *S="IVXLCDM ";
int c[256];
int i, j, temp, n;
int main(){
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        temp=i;
        for(j=0; A[temp%10][j]^' '; j++) c[A[temp%10][j]]++; temp/=10;
        for(j=0; B[temp%10][j]^' '; j++) c[B[temp%10][j]]++; temp/=10;
        for(j=0; C[temp%10][j]^' '; j++) c[C[temp%10][j]]++; temp/=10;
        for(j=0; D[temp%10][j]^' '; j++) c[D[temp%10][j]]++; temp/=10;
    }
    for(i=0; S[i]^' '; i++) if(c[S[i]]) printf("%c %d\n", S[i], c[S[i]]);
    return 0;
}
