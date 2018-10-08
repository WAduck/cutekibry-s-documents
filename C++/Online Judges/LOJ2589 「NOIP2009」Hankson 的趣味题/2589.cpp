/*
gcd(x, a0)=a1
lcm(x, b0)=b1

True: a1|x          (b1/b0)|x
False: anyof(a0/a1)|x        except(b1)|x
*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
struct Node{
    int v, t;
    Node(int _v=0, int _t=0){ v=_v; t=_t; }
    Node operator = (Node b){ v=b.v; t=b.t; return *this; }
    bool operator < (Node _node){ if(v^_node.v) return v<_node.v; else return t>_node.t; }
};
Node must[105], mustnt[105], able[105]; int mustn, mustntn, ablen;
Node a[105], b[105]; int an, bn;
int i, j, a0, a1, b0, b1, T;
int64 ans;
inline void trans(int x, Node a[], int &an, bool needsort=false){
    int i, j, cnt, tmp=x;
    for(i=2; i*i<=tmp; i++) if(!(tmp%i)){
        cnt=0;
        while(!(tmp%i)) cnt++, tmp/=i;
        a[++an]=Node(i, cnt);
    }
    if(tmp>>1) a[++an]=Node(tmp, 1);
    if(needsort){
        sort(a+1, a+an+1);
        j=0; i=1;
        while(i<=an){
            tmp=i;
            a[++j]=a[i];
            while(a[tmp].v==a[i].v) i++;
        }
        an=j;
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        mustn=mustntn=ablen=an=0;
        ans=1;
        for(i=1; i<=100; i++) must[i]=mustnt[i]=able[i]=a[i]=Node();
        scanf("%d %d %d %d", &a0, &a1, &b0, &b1);
        trans(b0, a, an, true);
        // trans(a0/a1, mustnt, mustntn, true); // for(i=1; i<=mustntn; i++) mustnt[i].t=1;
        trans(b1, able, ablen, true);

        j=1;
        for(i=1; i<=ablen; i++){
            while(j<=an and able[i].v>a[j].v) j++;
            // printf("# %d^%d %d^%d\n", able[i].v, able[i].t, a[j].v, a[j].t);
            if(a[j].t<able[i].t or a[j].v^able[i].v) must[++mustn]=able[i];
        }
        trans(a1, must, mustn, true);

        an=bn=0;
        for(i=1; i<=100; i++) a[i]=b[i]=Node();
        trans(a0/a1, a, an, true);
        trans(a1, b, bn, true);
        j=1;
        for(i=1; i<=an; i++){
            while(j<=bn and a[i].v>b[j].v) j++;
            // printf("# %d^%d %d^%d\n", able[i].v, able[i].t, a[j].v, a[j].t);
            if(a[i].v^b[j].v) mustnt[++mustntn]=Node(a[i].v, 1);
            else mustnt[++mustntn]=Node(a[i].v, b[j].t+1);
        }
        trans(1, mustnt, mustntn, true);

        // for(i=1; i<=mustn; i++) printf("%d^%d ", must[i].v, must[i].t); putchar('\n');
        // for(i=1; i<=mustntn; i++) printf("%d^%d ", mustnt[i].v, mustnt[i].t); putchar('\n');
        // for(i=1; i<=ablen; i++) printf("%d^%d ", able[i].v, able[i].t); putchar('\n');

        j=1;
        for(i=1; i<=mustn and ans; i++){
            while(j<=mustntn and must[i].v>mustnt[j].v) j++;
            if(must[i].v==mustnt[j].v and must[i].t>=mustnt[j].t) ans=0;
        }

        // printf("#1 ans=%d\n", ans);

        j=1;
        for(i=1; i<=ablen and ans; i++){
            while(j<=mustntn and able[i].v>mustnt[j].v) j++;
            if(able[i].v==mustnt[j].v) able[i].t=min(able[i].t, mustnt[j].t-1);
        }

        // printf("#2 ans=%d\n", ans);

        j=1;
        for(i=1; i<=ablen and ans; i++){
            while(j<=mustn and able[i].v>must[j].v) j++;
            // printf("%d %d %d\n", i, j, ans);
            if(able[i].v==must[j].v){
                if(able[i].t<must[j].t) ans=0;
                else ans*=able[i].t-must[j].t+1;
            }
            else ans*=able[i].t+1;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
