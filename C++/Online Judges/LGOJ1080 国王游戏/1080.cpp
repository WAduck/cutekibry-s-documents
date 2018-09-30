#include <cstdio>
#include <algorithm>
#include <cstring>
#define ri register int
using namespace std;
struct hugeint{
    int a[10005];
    int len;
    hugeint(){ memset(a, 0, sizeof(a)); len=1; }
    hugeint operator = (hugeint b){ memcpy(a, b.a, sizeof(b.a)); len=b.len; return *this; }
    hugeint operator * (int x){
        hugeint ans;
        ri i;
        ans.len=len+9;
        for(i=1; i<=ans.len; i++){
            ans.a[i]+=a[i]*x;
            ans.a[i+1]+=ans.a[i]/10;
            ans.a[i]%=10;
        }
        while(!ans.a[ans.len] and ans.len>1) ans.len--;
        return ans;
    }
    hugeint operator / (int x){
        hugeint ans=(*this);
        ri i;
        ans.len=len;
        for(i=ans.len; i; i--){
            ans.a[i-1]+=ans.a[i]%x*10;
            ans.a[i]/=x;
        }
        ans.a[0]=0;
        while(!ans.a[ans.len] and ans.len>1) ans.len--;
        return ans;
    }
    bool operator < (hugeint b){
        if(len^b.len) return len<b.len;
        ri i;
        for(i=len; i; i--) if(a[i]^b.a[i]) return a[i]<b.a[i];
        return false;
    }
    bool operator > (hugeint b){
        return b < (*this);
    }
};
inline void write(hugeint x){
    ri i;
    for(i=x.len; i; i--) putchar(x.a[i]|48);
}
hugeint x, ans;
struct Node{
    int x, y;
    bool operator < (const Node _node) const{ return x*y < _node.x*_node.y; }
};
Node a[1005];
int i, j, n, ka, kb;
inline hugeint max(hugeint a, hugeint b){ return (a>b)?a:b; }
int main(){
    scanf("%d %d %d", &n, &ka, &kb);
    for(i=1; i<=n; i++) scanf("%d %d", &a[i].x, &a[i].y);
    sort(a+1, a+n+1);
    x.a[1]=1;
    x=x*ka;
    for(i=1; i<=n; i++){
        // printf("%d\n", i);
        ans=max(ans, x/a[i].y);
        x=x*a[i].x;
    }
    write(ans);
    return 0;
}
