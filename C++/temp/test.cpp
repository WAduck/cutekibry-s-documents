/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: test
*/
#include <cstdio>
int f[30*30*30*30];
// int f[40][50][40][50];
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    return 0;
}
