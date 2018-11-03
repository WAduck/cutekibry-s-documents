#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int TIMES=10;
inline int randint(int l, int r){ return rand()%(r-l+1)+l; }
int main(){
    srand(time(NULL));

    FILE *data, *out1, *out2;
    int i, j, t, n, m, u, v, w, x, y, z, cnt1, cnt2;

    system("g++ -o 1048 1048-sa.cpp -O3 -DONLINE_JUDGE");
    system("g++ -o 1048-2 1048-sa-2.cpp -O3 -DONLINE_JUDGE");

    cnt1=cnt2=0;
    for(t=1; t<=TIMES; t++){
        data=fopen("1048.in", "w");
        n=randint(90, 100);
        m=randint(900, 1000);
        fprintf(data, "%d %d\n", m, n);
        for(i=1; i<=n; i++){
            fprintf(data, "%d %d\n", randint(1, 100), randint(1, 100));
        }
        fclose(data);

        system("./1048 < 1048.in > 1048.out");
        system("./1048-2 < 1048.in > 1048-2.out");

        out1=fopen("1048.out", "r");
        out2=fopen("1048-2.out", "r");
        fscanf(out1, "%d", &x);
        fscanf(out2, "%d", &y);
        printf("%d ", t);
        if(x>y){
            printf("First program is better\n");
            cnt1++;
        }
        else if(x<y){
            printf("Second program is better\n");
            cnt2++;
        }
        else printf("Same\n");
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}
