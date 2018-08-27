/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: msquare
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SCP=682*999/6;
struct Square{
    int a[3][5];
    Square(){ memset(a, 0, sizeof(a)); }
    Square operator = (Square b){ memcpy(a, b.a, sizeof(b.a)); return *this; }
    int toint(){
        int res=0;
        for(int i=1; i<=4; i++) res=res*10+a[1][i];
        for(int i=4; i; i--) res=res*10+a[2][i];
        return res;
    }
    bool operator == (Square b){ return toint()==b.toint(); }
    Square aopt(){
        Square ans;
        for(int i=1; i<=4; i++) ans.a[1][i]=a[2][i], ans.a[2][i]=a[1][i];
        return ans;
    }
    Square bopt(){
        Square ans;
        ans.a[1][1]=a[1][4], ans.a[2][1]=a[2][4];
        for(int i=2; i<=4; i++) ans.a[1][i]=a[1][i-1], ans.a[2][i]=a[2][i-1];
        return ans;
    }
    Square copt(){
        Square ans;
        ans.a[1][1]=a[1][1]; ans.a[1][4]=a[1][4];
        ans.a[2][1]=a[2][1]; ans.a[2][4]=a[2][4];
        ans.a[1][2]=a[2][2]; ans.a[1][3]=a[1][2];
        ans.a[2][2]=a[2][3]; ans.a[2][3]=a[1][3];
        return ans;
    }
};
Square q[SCP]; int ql, qr;
Square u, v, t; int uid, vid, tid;
int i, j, k, n, m;
int pre[SCP], num[SCP], numn; char trans[SCP], stack[SCP]; int stop;
int vis[SCP];
inline int id(int x){ return lower_bound(num+1, num+1+numn, x)-num; }
void dfs(int dep, int x){
    int i;
    if(dep>8){
        num[++numn]=x;
        return;
    }
    for(i=1; i<=8; i++) if(!vis[i]){
        vis[i]=1;
        dfs(dep+1, x*10+i);
        vis[i]=0;
    }
}
int main(){
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    dfs(1, 0);
    sort(num+1, num+1+numn);
    ql=qr=1;
    for(i=1; i<=4; i++) scanf("%d", &t.a[1][i]), q[1].a[1][i]=i;
    for(i=4; i; i--) scanf("%d", &t.a[2][i]), q[1].a[2][i]=9-i;
    tid=id(t.toint());
    vis[1]=1;
    while(ql<=qr){
        u=q[ql];
        uid=id(u.toint());
        if(uid==tid){
            printf("%d\n", vis[uid]-1);
            // for(i=ql; pre[i]; i=pre[i]) printf("%d\n", q[i].toint());
            for(i=ql; pre[i]; i=pre[i]) stack[++stop]=trans[i];
            while(stop) putchar(stack[stop--]);
            putchar('\n');
            return 0;
        }

        v=u.aopt(); vid=id(v.toint());
        if(!vis[vid]){
            vis[vid]=vis[uid]+1;
            q[++qr]=v;
            pre[qr]=ql;
            trans[qr]='A';
        }

        v=u.bopt(); vid=id(v.toint());
        if(!vis[vid]){
            vis[vid]=vis[uid]+1;
            q[++qr]=v;
            pre[qr]=ql;
            trans[qr]='B';
        }

        v=u.copt(); vid=id(v.toint());
        if(!vis[vid]){
            vis[vid]=vis[uid]+1;
            q[++qr]=v;
            pre[qr]=ql;
            trans[qr]='C';
        }
        ql++;
    }
}
