/*
Algorithm: Discretization + Segtree
Time complexity: O(n log n)
*/
#include <cstdio>
#include <algorithm>
int sum[100005<<2], l[100005<<2], r[100005<<2];
int _num[100005];
int qopt[100005], qx[100005];
int n;
void _buildtree(int p){
    if(l[p]^r[p]){
        l[p<<1]=l[p];
        r[p<<1]=(l[p]+r[p])>>1;
        l[p<<1|1]=r[p<<1]+1;
        r[p<<1|1]=r[p];
        _buildtree(p<<1);
        _buildtree(p<<1|1);
    }
}
int _rank(int x){
    int l=1, r=n, mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(_num[mid]<x) l=mid;
        else if(_num[mid]==x) return mid;
        else r=mid-1;
    }
    return l;
}
int _query(int p, int a, int b){
    if(b<l[p] or a>r[p]) return 0;
    if(a<=l[p] and r[p]<=b) return sum[p];
    return _query(p<<1, a, b)+_query(p<<1|1, a, b);
}
int _pos(int x){
    int p=1, mid;
    while(l[p]<r[p]){
        if(x<=r[p<<1]) p=p<<1;
        else p=p<<1|1;
    }
    return p;
}
void insert(int x){
    x=_rank(x);
    int p=1, mid;
    while(l[p]^r[p]){
        sum[p]++;
        if(x<=r[p<<1]) p=p<<1;
        else p=p<<1|1;
    }
    sum[p]++;
}
void del(int x){
    x=_rank(x);
    int p=1, mid;
    while(l[p]^r[p]){
        sum[p]--;
        if(x<=r[p<<1]) p=p<<1;
        else p=p<<1|1;
    }
    sum[p]--;
}
int rank(int x){
    x=_rank(x);
    return _query(1, 1, x-1)+1;
}
int num(int x){
    int p=1;
    x--;
    while(l[p]<r[p]){
        if(sum[p<<1]<=x){ x-=sum[p<<1]; p=p<<1|1; }
        else p=p<<1;
    }
    return _num[l[p]];
}
int before(int x){
    insert(x);
    int p=_pos(_rank(x)), ans;
    ans=num(rank(x)-1);
    del(x);
    return ans;
}
int after(int x){
    insert(x);
    int p=_pos(_rank(x)), ans;
    ans=num(rank(x)+sum[p]);
    del(x);
    return ans;
}
int main(){
    int i;

    scanf("%d", &n);
    l[1]=1; r[1]=n;
    _buildtree(1);
    for(i=1; i<=n; i++){
        scanf("%d %d", &qopt[i], &qx[i]);
        _num[i]=qx[i];
    }
    std::sort(_num+1, _num+1+n);
    for(i=1; i<=n; i++){
        switch(qopt[i]){
            case 1:{ insert(qx[i]); break; }
            case 2:{ del(qx[i]); break; }
            case 3:{ printf("%d\n", rank(qx[i])); break; }
            case 4:{ printf("%d\n", num(qx[i])); break; }
            case 5:{ printf("%d\n", before(qx[i])); break; }
            case 6:{ printf("%d\n", after(qx[i])); break; }
        }
    }
    return 0;
}
