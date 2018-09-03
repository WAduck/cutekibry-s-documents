/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: lgame
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG 0
#define $ if(DEBUG)
using namespace std;
const int SCP=682*999/2;
const int VAL[]={2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
char s[8], st[8], sa[8], sb[8];
char a[SCP][8]; int m;
int c[128], ct[128], ca[128], cb[128];
int i, j, k, l, p, ans;
inline void cnt(char input[], int output[]){
    int i;
    for(i='a'; i<='z'; i++) output[i]=0;
    for(i=1; input[i]; i++) output[input[i]]++;
    output[0]=0;
    for(i='a'; i<='z'; i++) output[0]+=output[i]*VAL[i-'a'];
}
inline bool trans(int input[], char output[]){
    int i, j, k=1;
    for(i='a'; i<='z' and input[i]>=0; i++) for(j=1; j<=input[i]; j++) output[k++]=i;
    return i>'z';
}
int main(){
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);

    FILE *DICT=fopen("lgame.dict", "r");
    fscanf(DICT, "%s", a[m+1]+1);
    while(a[m+1][1]!='.'){ m++; fscanf(DICT, "%s", a[m+1]+1); }
    scanf("%s", s+1);
    cnt(s, c);
    for(i=1, j=0; i<=m; i++){
        cnt(a[i], ct);
        for(k='a'; k<='z' and c[k]>=ct[k]; k++);
        if(k>'z'){
            j++;
            memcpy(a[j], a[i], sizeof(a[i]));
        }
    }
    m=j;
    for(i=1; i<=m; i++){
        memcpy(sa, a[i], sizeof(a[i]));
        cnt(sa, ca);
        ans=max(ans, ca[0]);
        for(j=i+1; j<=m; j++){
            memcpy(sb, a[j], sizeof(a[j]));
            cnt(sb, cb);
            for(k='a'; k<='z' and c[k]>=ca[k]+cb[k]; k++);
            if(k>'z') ans=max(ans, ca[0]+cb[0]);
        }
    }
    printf("%d\n", ans);
    for(i=1; i<=m; i++){
        memcpy(sa, a[i], sizeof(a[i]));
        cnt(sa, ca);
        if(ans==ca[0]) printf("%s\n", sa+1);
        for(j=i; j<=m; j++){
            memcpy(sb, a[j], sizeof(a[j]));
            cnt(sb, cb);
            for(k='a'; k<='z' and c[k]>=ca[k]+cb[k]; k++);
            if(k>'z' and ca[0]+cb[0]==ans) printf("%s %s\n", sa+1, sb+1);
        }
    }
    return 0;
}
