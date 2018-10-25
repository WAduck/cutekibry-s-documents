#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
const int maxn=600010;
int sum,ps,ans[maxn];
int n,m,x;
inline int minn(int a,int b){
    return a<b?a:b;
}
main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        sum+=x;
        ps+=x*x;
    }
    for(int i=1;i<=n;i++)
        ans[i]=(ps+i*sum*2+i*i*n)/i;
    for(int i=2;i<=n;i++)
        ans[i]=minn(ans[i-1],ans[i]);
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int opt;
        scanf("%lld",&opt);
        printf("%lld\n",ans[opt]);
    }
    return 0;
}