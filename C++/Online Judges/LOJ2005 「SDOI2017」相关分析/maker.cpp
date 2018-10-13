#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN=5, MAXA=5;
uint seed;
inline uint randint(uint l, uint r){ return (seed=seed*273+98641)%(r-l+1)+l; }
int main(){
    FILE *data, *out1, *out2;
    int i, n, m, opt, l, r, s, t;
    double x, y;
    system("g++ -o 2005 2005.cpp -g");
    system("g++ -o brust brust.cpp -g");
    while(1){
        data=fopen("2005.in", "w");
        n=randint(MAXN>>1, MAXN);
        m=randint(MAXN>>1, MAXN);
        // m=5;
        fprintf(data, "%d %d\n", n, m);
        for(i=1; i<=n; i++) fprintf(data, "%d ", randint(-MAXA, MAXA)); fprintf(data, "\n");
        for(i=1; i<=n; i++) fprintf(data, "%d ", randint(-MAXA, MAXA)); fprintf(data, "\n");
        for(i=1; i<=m; i++){
            opt=randint(1, 4);
            if(opt>1) opt--;
            l=randint(1, n);
            r=randint(l, n);
            s=randint(-MAXA, MAXA);
            t=randint(-MAXA, MAXA);
            if(opt>>1) fprintf(data, "%d %d %d %d %d\n", opt, l, r, s, t);
            else fprintf(data, "%d %d %d\n", opt, l, r);
        }
        fclose(data);
        system("./2005 < 2005.in > 2005.out");
        system("./brust < 2005.in > brust.out");
        out1=fopen("2005.out", "r");
        out2=fopen("brust.out", "r");
        while(~fscanf(out1, "%lf", &x)){
            y=2054986856;
            fscanf(out2, "%lf", &y);
            if(abs(x-y)>0.00001){
                printf("Uncorrect!!!\n");
                return 0;
            }
        }
        printf("correct\n");
        fclose(out1);
        fclose(out2);
    }
}
