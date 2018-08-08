#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
FILE *console=stdin;
int i, j, n, q, m, x;
int s[305][5005], stop[305], w[305][3005];
/*
limit: 107
count: n+4
A: O(n*logn)
B: O(n^3)
随便写个n=101的即可。
*/
void solve1(){
    memset(stop, 0, sizeof(stop));
    freopen("1.txt", "w", stdout);
    n=101;
    printf("%d\n", n);
    for(i=0; i<n; i++) printf("0\n");
    printf("1\n0 0");
    fclose(stdin);
}

/*
limit: 2222
count: 2+n+2m+2q
A: O(n^3)
B: O(q*(n-1)*m)
对所有1<i<n的i连一条i->(i-1)的边。
这样可以把Bellman-Ford卡到O((n-1)*m)。
*/
void solve2(){
    memset(stop, 0, sizeof(stop));
    freopen("2.txt", "w", stdout);
    n=100;
    m=1040;
    q=10;
    printf("%d\n", n);
    for(i=1; i<n; i++){
        m--;
        s[i][++stop[i]]=i-1;
    }
    for(i=0; i<n and m; i++){
        while(stop[i]<n-1 and m){
            m--;
            s[i][++stop[i]]=i;
        }
    }
    for(i=0; i<n; i++){
        printf("%d ", stop[i]);
        for(j=1; j<=stop[i]; j++) printf("%d 1 ", s[i][j]);
        putchar('\n');
    }
    printf("%d\n", q);
    for(i=0; i<q; i++) printf("%d 0\n", n-1);
    fclose(stdin);
}

/*
limit: 105
count: n+4
A: O(q*(n-1)*m)
B: O(n^3)
同subtask 1。
*/
void solve3(){
    memset(stop, 0, sizeof(stop));
    freopen("3.txt", "w", stdout);
    n=101;
    printf("%d\n", n);
    for(i=0; i<n; i++) printf("0\n");
    printf("1\n0 0");
    fclose(stdin);
}

/*
limit: 157
count: 4n+2q-2
A: O(n^3)
B: O(Q2^(n/2))
考虑如下的一个图。

*/
void solve4(){
    memset(stop, 0, sizeof(stop));
    freopen("4.txt", "w", stdout);
    n=32;
    q=10;
    x=2;
    printf("%d\n", n);
    for(i=0; i<n; i++){
        if((i+1)%x){
            if(i>=x){
                s[i][++stop[i]]=i-x;
                w[i][stop[i]]=0;
            }
            s[i][++stop[i]]=i+1;
            w[i][stop[i]]=1<<(i/x);
        }
        else{
            if(i>=x) s[i][++stop[i]]=i-x*2+1;
            w[i][stop[i]]=-(2<<(i/x));
        }
    }
    for(i=0; i<n; i++){
        printf("%d ", stop[i]);
        for(j=1; j<=stop[i]; j++)
            printf("%d %d ", s[i][j], w[i][j]);
        printf("\n");
    }
    printf("%d\n", q);
    for(i=1; i<=q; i++) printf("%d %d\n", n-x, x-1);
    fclose(stdin);
}

int main(){
    solve1();
    solve2();
    solve3();
    solve4();
    return 0;
}
