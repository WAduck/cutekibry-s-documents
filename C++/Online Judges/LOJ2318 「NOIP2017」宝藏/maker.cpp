#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
inline int randint(int l, int r){ return rand()%(r-l+1)+l; }
int main(){
    srand(time(NULL));

    FILE *data, *out1, *out2;
    int n, m, i, j, k, t, x, y, u, v, w;

    system("g++ -o 2318 2318-sa.cpp -O3 -DONLINE_JUDGE && g++ -o 2318-2 2318-sa-2.cpp -O3 -DONLINE_JUDGE");

    t=0;
    while(1){
        t++;

        data=fopen("2318.in", "w");
        n=12;
        m=randint(100, 1000);
        fprintf(data, "%d %d\n", n, m);
        for(i=1; i<=m; i++){
            x=randint(1, n);
            do y=randint(1, n); while(x==y);
            fprintf(data, "%d %d %d\n", x, y, randint(1, 100000));
        }
        fclose(data);

        system("./2318 < 2318.in > 2318.out && ./2318-2 < 2318.in > 2318-2.out");

        out1=fopen("2318.out", "r");
        out2=fopen("2318-2.out", "r");
        fscanf(out1, "%d", &x);
        fscanf(out2, "%d", &y);
        if(x<y){
            printf("First program is better");
            return 0;
        }
        else if(x>y){
            printf("Second program is better");
            return 0;
        }
        printf("%d correct\n", t);
        fclose(out1);
        fclose(out2);
    }
}
