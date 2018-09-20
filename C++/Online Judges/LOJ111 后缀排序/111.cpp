#include <cstdio>
#include <algorithm>
#define ri register int
using namespace std;
const int SCP=682*999*2;
int a[SCP], c[SCP], sa[SCP], xx[SCP*2], yy[SCP*2];
int *x, *y;
int n, m;
char s[SCP];
inline void getsa(){
    ri i, j, k=0;
    x=xx;
    y=yy;
    for(i=1; i<=n; i++) c[x[i]=a[i]]++;
    for(i=1; i<=m; i++) c[i]+=c[i-1];
    for(i=n; i; i--) sa[c[x[i]]--]=i;
    for(j=1; j<=n and k<=n; j<<=1){
        k=0;
        for(i=n-j+1; i<=n; i++) y[++k]=i;
        for(i=1; i<=n; i++) if(sa[i]>j) y[++k]=sa[i]-j;
        for(i=1; i<=m; i++) c[i]=0;
        for(i=1; i<=n; i++) c[x[y[i]]]++;
        for(i=1; i<=m; i++) c[i]+=c[i-1];
        for(i=n; i; i--) sa[c[x[y[i]]]--]=y[i];
        swap(x, y);
        k=2;
        x[sa[1]]=1;
        for(i=2; i<=n; i++) x[sa[i]]=(y[sa[i]]==y[sa[i-1]] and y[sa[i]+j]==y[sa[i-1]+j])?k-1:k++;
        m=k;
    }
}
int main(){
    scanf("%s", s+1);
    for(n=1; s[n]; n++) a[n]=s[n]-' ';
    n--;
    m=128;
    getsa();
    for(ri i=1; i<=n; i++) printf("%d ", sa[i]);
    return 0;

}
