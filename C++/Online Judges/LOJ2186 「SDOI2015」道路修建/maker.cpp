#include <cstdio>
#include <cstdlib>
#define y0 y00000
#define y1 y11111
using namespace std;
const int MAXN=10, MAXAI=10;
uint seed;
inline uint randint(uint l, uint r){ return (seed=(seed<<3)^(seed>>7)^(seed>>13)^17652231)%(r-l+1)+l; }
int main(){
    FILE *data, *out1, *out2;
    int x, y, n, m, i, j, opt, x0, x1, y0, y1, t=0;

    system("g++ -o 2186 2186.cpp -g");
    system("g++ -o brust brust.cpp -g");
    while(1){
        data=fopen("2186.in", "w");
        n=randint(MAXN>>1, MAXN);
        m=randint(MAXN>>1, MAXN);
        fprintf(data, "%d %d\n", n, m);
        for(i=1; i<n; i++) fprintf(data, "%d ", randint(1, MAXAI)); fprintf(data, "\n");
        for(i=1; i<n; i++) fprintf(data, "%d ", randint(1, MAXAI)); fprintf(data, "\n");
        for(i=1; i<=n; i++) fprintf(data, "%d ", randint(1, MAXAI)); fprintf(data, "\n");
        for(i=1; i<=m; i++){
            if(randint(0, 1)){
                if(randint(0, 1)){
                    x0=x1=randint(1, 2);
                    y0=randint(1, n-1);
                    y1=y0+1;
                }
                else{
                    y0=y1=randint(1, n);
                    if(randint(0, 1)) x0=1, x1=2;
                    else x0=2, x1=1;
                }
                fprintf(data, "C %d %d %d %d %d\n", x0, y0, x1, y1, randint(1, MAXAI));
            }
            else{
                y0=randint(1, n);
                y1=randint(y0, n);
                fprintf(data, "Q %d %d\n", y0, y1);
            }
        }
        fclose(data);
        // if(t==3) break;
        system("./2186 < 2186.in > 2186.out");
        system("./brust < 2186.in > brust.out");
        out1=fopen("2186.out", "r");
        out2=fopen("brust.out", "r");
        while(~fscanf(out1, "%d", &x)){
            y=129758261;
            fscanf(out2, "%d", &y);
            if(x^y){
                printf("Uncorrect!!!\n");
                fclose(out1); fclose(out2);
                return 0;
            }
        }
        printf("%d Correct\n", t++);
        fclose(out1); fclose(out2);
    }
    return 0;
}
