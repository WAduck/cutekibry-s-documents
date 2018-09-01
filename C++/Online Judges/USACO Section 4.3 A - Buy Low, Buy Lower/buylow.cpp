/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: buylow
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/120;
struct Hugeint{
    int a[105], len;
    Hugeint (){
        memset(a, 0, sizeof(a));
        len=1;
    }
    Hugeint (int x){
        memset(a, 0, sizeof(a));
        len=0;
        while(x){
            a[++len]=x%10;
            x/=10;
        }
        if(!len) len=1;
    }
    Hugeint operator = (Hugeint b){
        memcpy(a, b.a, sizeof(b.a));
        len=b.len;
        return *this;
    }
    Hugeint operator + (Hugeint b){
        Hugeint ans;
        int i, j;
        ans.len=max(len, b.len)+1;
        for(i=1; i<=ans.len; i++){
            ans.a[i]+=a[i]+b.a[i];
            if(ans.a[i]>=10){
                ans.a[i]-=10;
                ans.a[i+1]++;
            }
        }
        while(!ans.a[ans.len] and ans.len>1) ans.len--;
        return ans;
    }
};
inline void writeln(Hugeint x){
    for(int i=x.len; i; i--) putchar(x.a[i]|48);
    putchar('\n');
}
int a[SCP], num[SCP], n, i, j;
int f[SCP];
Hugeint f2[SCP];
bool c[SCP];
int main(){
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &a[i]), num[i]=a[i];
    n++;
    sort(num+1, num+1+n);
    for(i=1; i<=n; i++) a[i]=lower_bound(num+1, num+1+n, a[i])-num;
    f[1]=1;
    f2[1]=Hugeint(1);
    for(i=2; i<=n; i++){
        for(j=1; j<i; j++) if(a[i]<a[j]) f[i]=max(f[i], f[j]);
        if(!f[i]) f2[i]=Hugeint(1);
        f[i]++;
        for(j=i-1; j; j--) if(a[i]<a[j] and f[i]==f[j]+1 and !c[a[j]]) f2[i]=f2[i]+f2[j], c[a[j]]=true;
        for(j=i-1; j; j--) c[a[j]]=false;
    }
    f[n]=0;
    for(i=1; i<n; i++) f[n]=max(f[n], f[i]);
    printf("%d ", f[n]);
    writeln(f2[n]);
    return 0;
}
