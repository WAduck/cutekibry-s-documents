/*
Algorithm: Block
Time complexity: O(n sqrt n)
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int v[100005], t[100005];
int size[350];
int blocksize, n;
int qopt[100005], qx[100005];
inline int _getblock(int p){ //获得p所在的分块
    return (p-1)/blocksize+1;
}
inline int _getpos(int x){ //获得x所在的下标
    int l=1, r=n, mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(x<v[mid]) r=mid-1;
        else if(x==v[mid]) return mid;
        else l=mid;
    }
    return l;
}
void insert(int x){ //插入
    int p=_getpos(x);
    size[_getblock(p)]++;
    t[p]++;
}
void del(int x){ //删除
    int p=_getpos(x);
    size[_getblock(p)]--;
    t[p]--;
}
int rank(int x){ //获得x的排名
    int i, ans=1, p=_getpos(x);
    for(i=blocksize; i<p; i+=blocksize) ans+=size[_getblock(i)];
    for(i=i-blocksize+1; i<p; i++) ans+=t[i];
    return ans;
}
int invrank(int x){ //获得排名为x的数
    int i;
    x--;
    for(i=blocksize; x>=size[_getblock(i)]; i+=blocksize) x-=size[_getblock(i)];
    for(i=i-blocksize+1; x>=t[i]; i++) x-=t[i];
    return v[i];
}
int before(int x){ //x的前继
    int i, p=_getpos(x);
    for(i=p-1; _getblock(i)==_getblock(p); i--) if(t[i]) return v[i];
    for(i=_getblock(i); !size[i]; i--);
    for(i=i*blocksize; ; i--) if(t[i]) return v[i];
}
int after(int x){ //x的后继
    int i, p=_getpos(x);
    for(i=p+1; _getblock(i)==_getblock(p); i++) if(t[i]) return v[i];
    for(i=_getblock(i); !size[i]; i++);
    for(i=(i-1)*blocksize+1; ; i++) if(t[i]) return v[i];
}
int main(){
    int i, j;
    int m;

    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &qopt[i], &qx[i]);
        if(qopt[i]^3 and qopt[i]^4)
            v[++n]=qx[i];
    }

    std::sort(v+1, v+1+n);
    v[n+1]=~v[n];
    for(i=1, j=0; i<=n; i++) if(v[i]^v[i+1]) v[++j]=v[i];
    n=j;
    blocksize=sqrt(n);

    for(i=1; i<=m; i++){
        switch(qopt[i]){
            case 1: insert(qx[i]); break;
            case 2: del(qx[i]); break;
            case 3: printf("%d\n", rank(qx[i])); break;
            case 4: printf("%d\n", invrank(qx[i])); break;
            case 5: printf("%d\n", before(qx[i])); break;
            case 6: printf("%d\n", after(qx[i])); break;
        }
    }

    return 0;
}
