#include <cstdio>
void f(int p){
    if(p>1e6) printf("%d", p);
    else f(p+1);
}
int main(){
    f(1);
    return 0;
}
