// ...你有毒，拿我之前出的题目来交...
#include <stdio.h>
int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
int main(){
    int i, j, k, n, m;
    int opt, x, y;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        if(i==1) scanf("%d", &a1);
        else if(i==2) scanf("%d", &a2);
        else if(i==3) scanf("%d", &a3);
        else if(i==4) scanf("%d", &a4);
        else if(i==5) scanf("%d", &a5);
        else if(i==6) scanf("%d", &a6);
        else if(i==7) scanf("%d", &a7);
        else if(i==8) scanf("%d", &a8);
        else if(i==9) scanf("%d", &a9);
        else if(i==10) scanf("%d", &a10);
    }
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &opt, &x, &y);
        if(opt==1){
            for(j=1; j<=y; j++){
                for(k=1; k<=y; k++){
                    if(x==1) a1=(a1+j*k)%100;
                    else if(x==2) a2=(a2+j*k)%100;
                    else if(x==3) a3=(a3+j*k)%100;
                    else if(x==4) a4=(a4+j*k)%100;
                    else if(x==5) a5=(a5+j*k)%100;
                    else if(x==6) a6=(a6+j*k)%100;
                    else if(x==7) a7=(a7+j*k)%100;
                    else if(x==8) a8=(a8+j*k)%100;
                    else if(x==9) a9=(a9+j*k)%100;
                    else if(x==10) a10=(a10+j*k)%100;
                }
            }
        }
        else{
            int ans=0;
            for(j=x; j<=y; j++){
                if(j==1) ans=(ans+a1)%100;
                else if(j==2) ans=(ans+a2)%100;
                else if(j==3) ans=(ans+a3)%100;
                else if(j==4) ans=(ans+a4)%100;
                else if(j==5) ans=(ans+a5)%100;
                else if(j==6) ans=(ans+a6)%100;
                else if(j==7) ans=(ans+a7)%100;
                else if(j==8) ans=(ans+a8)%100;
                else if(j==9) ans=(ans+a9)%100;
                else if(j==10) ans=(ans+a10)%100;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
C++：

#include <cstdio>
using namespace std;
int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
int main(){
    int i, j, k, n, m;
    int opt, x, y;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        if(i==1) scanf("%d", &a1);
        else if(i==2) scanf("%d", &a2);
        else if(i==3) scanf("%d", &a3);
        else if(i==4) scanf("%d", &a4);
        else if(i==5) scanf("%d", &a5);
        else if(i==6) scanf("%d", &a6);
        else if(i==7) scanf("%d", &a7);
        else if(i==8) scanf("%d", &a8);
        else if(i==9) scanf("%d", &a9);
        else if(i==10) scanf("%d", &a10);
    }
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &opt, &x, &y);
        if(opt==1){
            for(j=1; j<=y; j++){
                for(k=1; k<=y; k++){
                    if(x==1) a1=(a1+j*k)%100;
                    else if(x==2) a2=(a2+j*k)%100;
                    else if(x==3) a3=(a3+j*k)%100;
                    else if(x==4) a4=(a4+j*k)%100;
                    else if(x==5) a5=(a5+j*k)%100;
                    else if(x==6) a6=(a6+j*k)%100;
                    else if(x==7) a7=(a7+j*k)%100;
                    else if(x==8) a8=(a8+j*k)%100;
                    else if(x==9) a9=(a9+j*k)%100;
                    else if(x==10) a10=(a10+j*k)%100;
                }
            }
        }
        else{
            int ans=0;
            for(j=x; j<=y; j++){
                if(j==1) ans=(ans+a1)%100;
                else if(j==2) ans=(ans+a2)%100;
                else if(j==3) ans=(ans+a3)%100;
                else if(j==4) ans=(ans+a4)%100;
                else if(j==5) ans=(ans+a5)%100;
                else if(j==6) ans=(ans+a6)%100;
                else if(j==7) ans=(ans+a7)%100;
                else if(j==8) ans=(ans+a8)%100;
                else if(j==9) ans=(ans+a9)%100;
                else if(j==10) ans=(ans+a10)%100;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
