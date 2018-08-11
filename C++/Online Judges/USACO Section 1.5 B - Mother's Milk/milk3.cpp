/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: milk3
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int lim[5];
const int SCP=682*999/3;
int toint(int x, int y, int z){ return x*21*21+y*21+z; }
struct Node{
    int a[5];
    Node(){}
    Node(int x, int y, int z){ a[1]=x; a[2]=y; a[3]=z; }
    Node operator = (Node b){ memcpy(a, b.a, sizeof(b.a)); return *this; }
    Node fill(int x, int y){
        Node ans=(*this);
        int filled=min(lim[y]-a[y], a[x]);
        ans.a[x]-=filled;
        ans.a[y]+=filled;
        return ans;
    }
    int toint(){ return a[1]*21*21+a[2]*21+a[3]; }
};
Node q[SCP], u, v; int ql, qr, i, j, k;
bool vis[SCP];
int main(){
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    scanf("%d %d %d", &lim[1], &lim[2], &lim[3]);
    q[ql=qr=1]=Node(0, 0, lim[3]);
    vis[q[1].toint()]=1;
    while(ql<=qr){
        u=q[ql++];
        // printf("# %d %d %d\n", u.a[1], u.a[2], u.a[3]);
        for(i=1; i<=3; i++) for(j=1; j<=3; j++) if(i^j and u.a[i] and u.a[j]<lim[j]){
            v=u.fill(i, j);
            if(!vis[v.toint()]){
                vis[v.toint()]=1;
                q[++qr]=v;
            }
        }
    }
    for(i=0; i<lim[3]; i++){
        for(j=0; j<=lim[2] and !vis[toint(0, j, i)]; j++);
        if(j<=lim[2]) printf("%d ", i);
    }
    printf("%d\n", lim[3]);
    return 0;
}
