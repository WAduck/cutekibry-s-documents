#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int f[105][25];
int main(){
    int i, j;
    int m, s, t;
    int curt, curs;

    scanf("%d %d %d", &m, &s, &t);
    curs=s;
    curt=t;
    while(m>=10 and curs>=0 and curt>=1){ //把魔法耗掉
        m-=10;
        curs-=60;
        curt--;
    }
    while(curs>=240 and curt>=14){ //蹦跶术
        curs-=120;
        curt-=7;
    }
    if(curs<=0){
        printf("Yes\n%d", t-curt);
        return 0;
    }

    //DP
    for(i=1; i<=curt; i++){
        for(j=0; j<=m; j++){
            if(j+10<=m)
                f[i][j]=f[i-1][j+10]+60;
            if(j<=m)
                f[i][j]=max(f[i][j], f[i-1][j]+17);
            if(j-4>=0 and j-4<=m)
                f[i][j]=max(f[i][j], f[i-1][j-4]);
            if(f[i][j]>=curs)
                break;
        }
        if(j<=m){
            printf("Yes\n%d", t-curt+i);
            return 0;
        }
        m+=4;
        if(m>20)
            m=20;
    }
    printf("No\n%d", s-curs+f[curt][0]);
    return 0;
} 
