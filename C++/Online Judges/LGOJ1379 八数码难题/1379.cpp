#include <cstdio>
#include <algorithm>
using namespace std;
const int CP=682*999, MX[]={1, 0, -1, 0}, MY[]={0, 1, 0, -1};
bool vis[10];
int num[CP], numn;
int q[CP], ql, qr;
int dis[CP];
int i, j, k, x, y, u, v, uid, vid, tid, tmp, a[5][5];
inline void read(int &x){ register char ch; register bool neg=0; do ch=getchar(); while((ch<'0' or ch>'9') and ch^'-'); if(!(ch^'-')) neg=1, ch=getchar(); x=0; while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch&15), ch=getchar(); if(neg) x=-x; }
inline void read(int &a, int &b){ read(a); read(b); }
inline void read(int &a, int &b, int &c){ read(a); read(b); read(c); }
inline void write(int x){ if(!x){ putchar('0'); return; } if(x<0) putchar('-'), x=-x; char buf[20]; register int top=0; while(x) buf[++top]=(x%10)|48, x/=10; while(top) putchar(buf[top--]); }
inline void writeln(int x){ write(x); putchar('\n'); }
void dfs(int dep, int tot){
    if(dep>9){
        num[++numn]=tot;
        return;
    }
    for(int i=0; i<9; i++) if(!vis[i]){
        vis[i]=1;
        dfs(dep+1, tot*10+i);
        vis[i]=0;
    }
}
inline int id(int x){ return lower_bound(num+1, num+1+numn, x)-num; }
int main(){
    dfs(1, 0);
    sort(num+1, num+1+numn);
    read(q[ql=qr=1]);
    dis[id(q[1])]=1;
    tid=id(123804765);
    while(ql<=qr and !dis[tid]){
        u=q[ql++];
        uid=id(u);
        for(tmp=u, i=3; i; i--){
			for(j=3; j; j--){
        		a[i][j]=tmp%10;
        		if(!a[i][j]) x=i, y=j;
				tmp/=10;
        	}
        }
        for(k=0; k<4; k++) if(a[x+MX[k]][y+MY[k]]){
            swap(a[x][y], a[x+MX[k]][y+MY[k]]);
            v=0;
            for(i=1; i<=3; i++) for(j=1; j<=3; j++) v=v*10+a[i][j];
            if(!dis[vid=id(v)]){
                q[++qr]=v;
                dis[vid]=dis[uid]+1;
            }
            swap(a[x][y], a[x+MX[k]][y+MY[k]]);
        }
    }
    writeln(dis[tid]-1);
    return 0;
}
