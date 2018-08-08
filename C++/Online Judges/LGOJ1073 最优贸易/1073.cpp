#include <cstdio>
#include <cstring>
#include <algorithm>
#define rc register char
#define ri register int
using namespace std;
const int SCP=682*999/6, CP=682*999;
inline void read(int &x){ rc ch; do ch=getchar(); while(ch<'0' or ch>'9'); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); }
inline void write(int x){ if(!x){ putchar('0'); return; } if(x<0) putchar('-'), x=-x; char buf[25]; ri top=0; while(x) buf[++top]=(x%10)|48, x/=10; while(top) putchar(buf[top--]); }
int n, m, x, y, z, i, j, k, u, ulevel, v, vlevel;
int price[SCP];
int dis[SCP*3];
int pre[CP<<1], to[CP<<1], head[SCP], wcnt;
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
bool cmp(int x, int y){ return dis[x]<dis[y]; }
int pq[SCP*3], pqtop;
bool inq[SCP*3];
inline int top(){ return pq[0]; }
inline void push(int x){ pq[pqtop++]=x; push_heap(pq, pq+pqtop, cmp); }
inline void pop(){ pop_heap(pq, pq+pqtop--, cmp); }
inline bool empty(){ return !pqtop; }
int main(){
    memset(dis, 0x80, sizeof(dis));
    read(n); read(m);
    for(i=1; i<=n; i++) read(price[i]);
    for(i=1; i<=m; i++){
        read(x); read(y); read(z);
        addedge(x, y);
        if(z>>1) addedge(y, x);
    }
    dis[1]=0;
    push(1);
    while(!empty()){
        u=top();
        inq[u]=0;
        ulevel=(u-1)/n;
        u-=ulevel*n;
        pop();
        for(i=head[u]; i; i=pre[i]){
            if(dis[u+ulevel*n]>dis[(v=to[i])+ulevel*n]){
                dis[v+ulevel*n]=dis[u+ulevel*n];
                if(!inq[v+ulevel*n]){
                    push(v+ulevel*n);
                    inq[v+ulevel*n]=1;
                }
            }
            if(ulevel<2 and dis[u+ulevel]+(ulevel?1:-1)*price[v=to[i]]>dis[v+(ulevel+1)*n]){
                dis[v+(ulevel+1)*n]=dis[u+ulevel*n]+(ulevel?1:-1)*price[v];
                if(!inq[v+(ulevel+1)*n]){
                    push(v+(ulevel+1)*n);
                    inq[v+(ulevel+1)*n]=1;
                }
            }
        }
    }
    write(max(dis[3*n], 0));
    return 0;
}
