/*
Algorithm: Segtree in BIT
Time complexity: O(n log n log n)
*/
#include <cstdio>
#include <algorithm>
const int BCP=682*999*30, SCP=682*999/6;
int lson[BCP], rson[BCP], sum[BCP], cnt;
int root[SCP], num[SCP], numn;
int qopt[SCP], qx[SCP], qy[SCP], qz[SCP], a[SCP];
int xx[105], yy[105], xtop, ytop;
int n, m;
void update(int &p, int fp, int l, int r, int x, int y){
    int mid=(l+r)>>1;
    p=++cnt;
    lson[p]=lson[fp]; rson[p]=rson[fp]; sum[p]=sum[fp]+y;
    if(l==r) return;
    if(x<=mid) update(lson[p], lson[fp], l, mid, x, y);
    else update(rson[p], rson[fp], mid+1, r, x, y);
}
inline int lowbit(int x){ return x&-x; }
inline int id(int x){ return std::lower_bound(num+1, num+1+numn, x)-num; }
void add(int p, int x, int y){
    for(p=n-p+1; p<=n; p+=lowbit(p)) update(root[p], root[p], 1, numn, x, y);
}
void prepare(int l, int r){
    r++;
    xtop=ytop=0;
    for(l=n-l+1; l; l-=lowbit(l)) yy[++ytop]=root[l];
    for(r=n-r+1; r; r-=lowbit(r)) xx[++xtop]=root[r];
}
int queryrank(int l, int r, int x){
    int temp=0, mid=(l+r)>>1, i;
    if(l==r) return 0;
    if(x<=mid){
        for(i=1; i<=xtop; i++) xx[i]=lson[xx[i]];
        for(i=1; i<=ytop; i++) yy[i]=lson[yy[i]];
        return queryrank(l, mid, x);
    }
    else{
        for(i=1; i<=xtop; i++) temp-=sum[lson[xx[i]]];
        for(i=1; i<=ytop; i++) temp+=sum[lson[yy[i]]];
        for(i=1; i<=xtop; i++) xx[i]=rson[xx[i]];
        for(i=1; i<=ytop; i++) yy[i]=rson[yy[i]];
        return queryrank(mid+1, r, x)+temp;
    }
}
int queryinvrank(int l, int r, int x){
    int temp=0, mid=(l+r)>>1, i;
    if(l==r) return l;
    for(i=1; i<=xtop; i++) temp-=sum[lson[xx[i]]];
    for(i=1; i<=ytop; i++) temp+=sum[lson[yy[i]]];
    if(temp<=x){
        x-=temp;
        for(i=1; i<=xtop; i++) xx[i]=rson[xx[i]];
        for(i=1; i<=ytop; i++) yy[i]=rson[yy[i]];
        return queryinvrank(mid+1, r, x);
    }
    else{
        for(i=1; i<=xtop; i++) xx[i]=lson[xx[i]];
        for(i=1; i<=ytop; i++) yy[i]=lson[yy[i]];
        return queryinvrank(l, mid, x);
    }
}
int querytimes(int l, int r, int x){
    int temp=0, mid=(l+r)>>1, i;
    if(l==r){
    	for(i=1; i<=xtop; i++) temp-=sum[xx[i]];
    	for(i=1; i<=ytop; i++) temp+=sum[yy[i]];
    	return temp;
	}
    if(x>mid){
        for(i=1; i<=xtop; i++) xx[i]=rson[xx[i]];
        for(i=1; i<=ytop; i++) yy[i]=rson[yy[i]];
        return querytimes(mid+1, r, x);
    }
    else{
        for(i=1; i<=xtop; i++) xx[i]=lson[xx[i]];
        for(i=1; i<=ytop; i++) yy[i]=lson[yy[i]];
        return querytimes(l, mid, x);
    }
}
int rank(int l, int r, int x){
    prepare(l, r);
    return queryrank(1, numn, x);
}
int invrank(int l, int r, int x){
    prepare(l, r);
    return queryinvrank(1, numn, x);
}
int times(int l, int r, int x){
    prepare(l, r);
    return querytimes(1, numn, x);
}
int before(int l, int r, int x){
    int rk=rank(l, r, x);
    if(!rk) return 0;
    else return invrank(l, r, rk-1);
}
int after(int l, int r, int x){
    int rk=rank(l, r, x), t=times(l, r, x);
    if(rk+t==r-l+1) return SCP-1;
    else return invrank(l, r, rk+t);
}
int main(){
    int i;

    num[0]=-2147483647;
    num[SCP-1]=2147483647;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){ scanf("%d", &a[i]); num[++numn]=a[i]; }
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &qopt[i], &qx[i], &qy[i]);
        if(qopt[i]^3){
			scanf("%d", &qz[i]);
			num[++numn]=qz[i];
		}
        else num[++numn]=qy[i];
    }
    std::sort(num+1, num+1+numn);
    for(i=1; i<=n; i++){ a[i]=id(a[i]); add(i, a[i], 1); }
    for(i=1; i<=m; i++){
        switch(qopt[i]){
            case 1: printf("%d\n", rank(qx[i], qy[i], id(qz[i]))+1); break;
            case 2: printf("%d\n", num[invrank(qx[i], qy[i], qz[i]-1)]); break;
            case 3:{
				add(qx[i], a[qx[i]], -1);
				a[qx[i]]=id(qy[i]);
				add(qx[i], a[qx[i]], 1);
				break;
			}
            case 4: printf("%d\n", num[before(qx[i], qy[i], id(qz[i]))]); break;
            case 5: printf("%d\n", num[after(qx[i], qy[i], id(qz[i]))]); break;
        }
    }
    return 0;
}
/*
8 10
93193828 87467295 7194563 77236060 94622726 47450113 70878734 52950301
2 6 8 2
5 4 6 89104605
3 7 62289938
3 4 94396652
4 7 7 36968499
4 8 8 42956931
4 1 2 30670581
5 7 7 7587866
1 7 7 74144921
1 3 3 53352412

52950301
94622726
-2147483647
-2147483647
-2147483647
62289938
2
2
*/
