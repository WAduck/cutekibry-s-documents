#include <cstdio>
#define rc register char
#define rb register bool
#define ri register int
#define lfp pp[lfid[i]]
#define lfl ll[lfid[i]]
#define lfr rr[lfid[i]]
#define mid ((l+r)>>1)
#define lson p<<1, l, mid
#define rson p<<1|1, mid+1, r

typedef long long int64;

#ifdef DEBUG
const int SCP=5000, LEN=30;
#else
const int SCP=682*999*2, LEN=30;
#endif
const int K=10000;
const int FULL=(1<<LEN)-1;
int seg[SCP<<2], a[SCP<<2], mark[SCP<<2];
int pp[105], ll[105], rr[105], top;
int lfid[105], lftop;
int n, m;


/* Read */
inline void read(int &x){
    rc ch; rb neg=0;
    do ch=getchar(); while(ch^'-' and (ch<'0' or ch>'9'));
    if(ch=='-') neg=1, ch=getchar();
    x=0;
    while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar();
    if(neg) x=-x;
}


/* Segtree */
inline int bitcount(int x){
    ri res=0;
    while(x) res++, x&=x-1;
    return res;
}
inline void addtree(int p, int l, int r, int x){
    if(x==-1){
        a[p]=0;
        mark[p]=-1;
        seg[p]=0;
    }
    else{
        a[p]=FULL;
        mark[p]=1;
        seg[p]=(r-l+1)*LEN;
    }
}
inline void down(int p, int l, int r){
    if(mark[p]){
        addtree(lson, mark[p]);
        addtree(rson, mark[p]);
        mark[p]=0;
    }
}
inline void prepare(int x){
    ri i, p, l, r;
    pp[top=1]=1; ll[1]=1; rr[1]=n;
    lftop=0;
    for(i=1; i<=top; i++){
        p=pp[i]; l=ll[i]; r=rr[i];
        if(x<=l){
            lfid[++lftop]=i;
            continue;
        }
        down(p, l, r);
        if(x<=mid) top++, pp[top]=p<<1, ll[top]=l, rr[top]=mid;
        top++, pp[top]=p<<1|1, ll[top]=mid+1, rr[top]=r;
    }
}
inline bool forceadd(int x, int k){
    ri p=1, l=1, r=n;
    rb res=0;
    while(l^r){
        down(p, l, r);
        if(x<=mid) p=p<<1, r=mid;
        else p=p<<1|1, l=mid+1;
    }
    a[p]+=k;
    if(a[p]<0){
        a[p]=FULL+a[p]+1;
        res=1;
    }
    else if(a[p]>>LEN){
        a[p]&=FULL;
        res=1;
    }
    seg[p]=bitcount(a[p]);
    for(p>>=1; p; p>>=1) seg[p]=seg[p<<1]+seg[p<<1|1];
    return res;
}
inline void decrease(int x){
    ri i, p, l, r;
    prepare(x);
    for(i=lftop; i and !seg[lfp]; i--) addtree(lfp, lfl, lfr, 1);
    p=lfp; l=lfl; r=lfr;
    while(l^r){
        down(p, l, r);
        if(seg[p<<1]) p=p<<1, r=mid;
        else addtree(lson, 1), p=p<<1|1, l=mid+1;
    }
    a[p]--;
    seg[p]=bitcount(a[p]);
    for(p>>=1; p; p>>=1) seg[p]=seg[p<<1]+seg[p<<1|1];
    for(i=top; i; i--) if(x>ll[i]) seg[pp[i]]=seg[pp[i]<<1]+seg[pp[i]<<1|1];
}
inline void increase(int x){
    ri i, p, l, r;
    prepare(x);
    for(i=lftop; i and seg[lfp]==(lfr-lfl+1)*LEN; i--) addtree(lfp, lfl, lfr, -1);
    p=lfp; l=lfl; r=lfr;
    while(l^r){
        down(p, l, r);
        if(seg[p<<1]<(mid-l+1)*LEN) p=p<<1, r=mid;
        else addtree(lson, -1), p=p<<1|1, l=mid+1;
    }
    a[p]++;
    seg[p]=bitcount(a[p]);
    for(p>>=1; p; p>>=1) seg[p]=seg[p<<1]+seg[p<<1|1];
    for(i=top; i; i--) if(x>ll[i]) seg[pp[i]]=seg[pp[i]<<1]+seg[pp[i]<<1|1];
}
inline bool query(int x, int y){
    ri p=1, l=1, r=n;
    while(l^r){
        down(p, l, r);
        if(x<=mid) p=p<<1, r=mid;
        else p=p<<1|1, l=mid+1;
    }
    return a[p]>>y&1;
}
void midorder(int p, int l, int r){
    if(l==r){
        ri i;
        for(i=LEN-1; i+1; i--) putchar((a[p]>>i&1)|48);
        return;
    }
    down(p, l, r);
    midorder(rson);
    midorder(lson);
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("2302.in", "r", stdin);
    freopen("2302.out", "w", stdout);
    #endif

    ri i, opt, x, x1, x2, y;
    rb neg;
    int64 temp;

    read(m); read(i); read(i); read(i);
    n=m+K;
    for(i=1; i<=m; i++){
        scanf("%d %d", &opt, &x);
        if(opt==1){
            scanf("%d", &y);
            if(x<0) neg=1, x=-x;
            else neg=0;
            temp=(int64)x<<(y%LEN);
            y=y/LEN+1;
            x1=temp>>LEN;
            x2=temp&FULL;
            x1+=forceadd(y, neg?-x2:x2);
            if(forceadd(y+1, neg?-x1:x1)){
                if(neg) decrease(y+2);
                else increase(y+2);
            }
            #ifdef DEBUG
            midorder(1, 1, n);
            putchar('\n');
            #endif
        }
        else
            putchar(query(x/LEN+1, x%LEN)|48), putchar('\n');
    }
    return 0;
}
