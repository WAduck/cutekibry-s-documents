#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define y0 y00000
#define y1 y11111
using namespace std;
const int SCP=100;
const int MAXN=100, MAXAI=10;
uint seed;
inline uint randint(uint l, uint r){ return (seed=(seed<<3)^(seed>>7)^(seed>>13)^17652231)%(r-l+1)+l; }
int far[SCP], ch[SCP][3];
int main(){
    FILE *data, *out1, *out2;
    int x, y, n, m, i, j, opt, x0, x1, y0, y1, t=0;

    system("g++ -o 2187 2187.cpp -g");
    system("g++ -o brust brust.cpp -g");
    while(1){
        memset(ch, 0, sizeof(ch));
        data=fopen("2187.in", "w");
        n=randint(MAXN>>1, MAXN);
        m=randint(MAXN>>1, MAXN);
        fprintf(data, "%d\n", n);
        if(n^1){
            far[2]=1;
            ch[1][0]=2;
        }
        for(i=3; i<=n; i++){
            do far[i]=randint(1, n); while(far[far[i]]==i or ch[far[i]][2]);
            if(!ch[far[i]][0]) ch[far[i]][0]=i;
            else if(!ch[far[i]][1]) ch[far[i]][1]=i;
            else ch[far[i]][2]=i;
        }
        j=n+1;
        for(i=1; i<=n; i++){
            if(!ch[i][0]) ch[i][0]=j++;
            if(!ch[i][1]) ch[i][1]=j++;
            if(!ch[i][2]) ch[i][2]=j++;
        }
        for(i=1; i<=n; i++) fprintf(data, "%d %d %d\n", ch[i][0], ch[i][1], ch[i][2]);
        for(i=1; i<=2*n+1; i++) fprintf(data, "%d ", randint(0, 1)); fprintf(data, "\n");
        fprintf(data, "%d\n", m);
        for(i=1; i<=m; i++) fprintf(data, "%d\n", randint(n+1, 3*n+1));
        fprintf(data, "\n# ");
        for(i=1; i<=3*n+1; i++) fprintf(data, "%d ", far[i]);
        fclose(data);
        // if(t==1) return 0;
        system("./2187 < 2187.in > 2187.out");
        system("./brust < 2187.in > brust.out");
        out1=fopen("2187.out", "r");
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
