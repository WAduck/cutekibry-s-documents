#include <cstdio>
#include <algorithm>
using namespace std;
const int SCP=682*999, INF=0x3fffffff;
int p[SCP], pn;
bool stone[SCP];
int a[SCP], f[SCP];
int n, s, t, l, ans=INF;
int i, j, k;
inline bool judge(int x, int y){
    return (y-x)%s<=(y-x)/s*(t-s);
}
int main(){
    scanf("%d %d %d %d", &l, &s, &t, &n);
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        p[++pn]=a[i];
        for(j=1; j<=3000; j++){
            if(a[i]-j>0) p[++pn]=a[i]-j;
            if(a[i]+j<l) p[++pn]=a[i]+j;
        }
    }
    p[++pn]=0;
    for(j=0; j<=3000; j++) p[++pn]=l+j;
    sort(p+1, p+1+pn);
    sort(a+1, a+1+n);
    pn=unique(p+1, p+1+pn)-p-1;
    for(i=j=1; i<=n; i++){
        while(j<=pn and p[j]^a[i]) j++;
        stone[j]=true;
    }
    for(i=2; i<=pn; i++){
        f[i]=INF;
        for(j=i-1; j and (j==i-1 or !judge(p[j], p[i-1])); j--) if(judge(p[j], p[i])) f[i]=min(f[i], f[j]);
        for(j=i-1; j and p[i]-p[j]<=t; j--) if(p[i]-p[j]>=s) f[i]=min(f[i], f[j]);
        f[i]+=stone[i];
    }
    for(i=pn; p[i]>=l; i--) ans=min(ans, f[i]);
    if(s==t) for(ans=0, i=1; i<=n; i++) ans+=!(a[i]%s);
	printf("%d", ans);
}
