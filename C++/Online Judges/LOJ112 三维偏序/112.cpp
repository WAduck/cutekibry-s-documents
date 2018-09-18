#include <cstdio>
#include <algorithm>
using namespace std;
const int SCP=682*999/3;
struct Node{
    int a, b, c, w, no;
};
Node a[SCP];
int ans[SCP];
int trueans[SCP];
int c[SCP];
int n, m;
bool cmpa(Node a, Node b){
    if(a.a^b.a) return a.a < b.a;
    if(a.b^b.b) return a.b < b.b;
    return a.c < b.c;
}
bool cmpb(Node a, Node b){
    if(a.b^b.b) return a.b < b.b;
    return a.c < b.c;
}
inline int lowbit(int x){ return x&-x; }
void add(int p, int x){
    for(; p<=m; p+=lowbit(p)) c[p]+=x;
}
int query(int p){
    int ans=0;
    for(; p; p-=lowbit(p)) ans+=c[p];
    return ans;
}
void cdq(int l, int r){
    int mid=(l+r)>>1, i, j;
    if(l==r) return;
    cdq(l, mid);
    cdq(mid+1, r);
    sort(a+l, a+mid+1, cmpb);
    sort(a+mid+1, a+r+1, cmpb);
    for(j=l, i=mid+1; i<=r; i++){
        while(a[j].b<=a[i].b and j<=mid) add(a[j++].c, a[j].w);
        ans[a[i].no]+=query(a[i].c);
    }
    for(i=l; i<j; i++) add(a[i].c, -a[i].w);
}
int main(){
	//freopen("data.in", "r", stdin);
	//freopen("temp.out", "w", stdout);
	
    int i, j, t;
    
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c);
    sort(a+1, a+1+n, cmpa);
    for(j=0, i=1; i<=n; i++){
        if(a[j].a^a[i].a or a[j].b^a[i].b or a[j].c^a[i].c){
            j++;
            a[j].a=a[i].a;
            a[j].b=a[i].b;
            a[j].c=a[i].c;
            a[j].no=j;
        }
        a[j].w++;
    }
    cdq(1, j);
    for(i=1; i<=j; i++)
        trueans[ans[a[i].no]+a[i].w-1]+=a[i].w;
    for(i=0; i<n; i++)
        printf("%d\n", trueans[i]);
    return 0;
}
/*
8 4
3 3 4
4 2 1
2 1 2
1 3 2
2 3 3
1 3 2
4 3 3
2 3 4

*/ 
