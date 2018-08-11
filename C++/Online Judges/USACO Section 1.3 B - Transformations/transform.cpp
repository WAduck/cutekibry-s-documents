/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <cstring>
using namespace std;
int n;
struct Square{
    char a[15][15];
    Square operator = (Square b){
        memcpy(a, b.a, sizeof(b.a));
        return *this;
    }
    bool operator == (Square b){
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i][j]^b.a[i][j]) return false;
        return true;
    }
    Square rotate90(){
        Square ans;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                ans.a[j][n-i+1]=a[i][j];
        return ans;
    }
    Square rotate180(){
        return (*this).rotate90().rotate90();
    }
    Square rotate270(){
        return (*this).rotate180().rotate90();
    }
    Square mirror(){
        Square ans;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                ans.a[i][n-j+1]=a[i][j];
        return ans;
    }
};
Square a, b;
int i, j;
int main(){
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%s", a.a[i]+1);
    for(i=1; i<=n; i++) scanf("%s", b.a[i]+1);
    if(a.rotate90()==b) printf("1\n");
    else if(a.rotate180()==b) printf("2\n");
    else if(a.rotate270()==b) printf("3\n");
    else if(a.mirror()==b) printf("4\n");
    else if(a.mirror().rotate90()==b or a.mirror().rotate180()==b or a.mirror().rotate270()==b) printf("5\n");
    else if(a==b) printf("6\n");
    else printf("7\n");
    return 0;
}
