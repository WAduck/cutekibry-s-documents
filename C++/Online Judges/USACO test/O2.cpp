/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: test
*/
#include <cstdio>
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int a, b;
    long long i;

    for(i=1; i<=1e18; i++); // This line will be TLE if compiler doesn't use -O2.
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    return 0;
}
