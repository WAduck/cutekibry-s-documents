/*
Let f[i][j][k]=the number of possibilities when we have chosen i numbers
                                                        which the sum=j
                                                        and content/not content(k) any primes.
Then
f[i][j][0]=sum(f[i-1][k][0]*(c[l]-cp[l])) ((k+l) mod m=j)
f[i][j][1]=sum(f[i-1][k][1]*c[l]+f[i-1][k][0]*cp[l]) ((k+l) mod m=j)
*/
#include <cstdio>
#include <cstring>
#define ri register int
#define DEBUG 0
#define $ if(DEBUG)
typedef long long int64;
const int MOD=20170408;
struct Matrix{
    int a[205][205], size;
    Matrix(int _size=0){ memset(a, 0, sizeof(a)); size=_size; }
    Matrix operator = (Matrix _matrix){ memcpy(a, _matrix.a, sizeof(_matrix.a)); size=_matrix.size; return *this; }
    Matrix operator * (Matrix b){
        Matrix ans=Matrix(size);
        ri i, j, k;
        for(i=1; i<=size; i++)
            for(j=1; j<=size; j++)
                for(k=1; k<=size; k++)
                    ans.a[i][j]=(ans.a[i][j]+(int64)a[i][k]*b.a[k][j])%MOD;
        return ans;
    }
};
bool vis[20000005];
int c[105], cp[105];
int ans;
Matrix b, res;
Matrix unitmatrix(int size){
    Matrix ans=Matrix(size);
    for(ri i=1; i<=size; i++) ans.a[i][i]=1;
    return ans;
}
Matrix qpow(Matrix b, int p){
    Matrix res=unitmatrix(b.size);
    while(p){
        if(p&1) res=res*b;
        b=b*b;
        p>>=1;
    }
    return res;
}
inline void writeln(Matrix b){
    ri i, j;
    for(i=1; i<=b.size; i++){
        for(j=1; j<=b.size; j++) printf("%d ", b.a[i][j]);
        putchar('\n');
    }
}
inline void modadd(int &x, int y, int mod){ x+=y; while(x>=mod) x-=mod; }
int main(){
    // freopen("2002.in", "r", stdin);
    // freopen("2002.out", "w", stdout);
    ri i, j, k, n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    vis[1]=1;
    for(i=2; i*i<=m; i++) if(!vis[i]) for(j=i*i; j<=m; j+=i) vis[j]=1;
    j=bool(p>>1);
    for(i=1; i<=m; i++){
        c[j]++;
        if(!vis[i]) cp[j]++;
        j++;
        if(!(j^p)) j=0;
    }

    b.size=p<<1;
    for(i=0; i<p; i++){
        for(j=0; j<p; j++){
            k=i; modadd(k, j, p);
            modadd(b.a[k<<1|1][i<<1|1], c[j]-cp[j], MOD);
            modadd(b.a[(k+1)<<1][(i+1)<<1], c[j], MOD);
            modadd(b.a[(k+1)<<1][i<<1|1], cp[j], MOD);
        }
    }

    $ printf("b=\n");
    $ writeln(b);
    res=qpow(b, n-1);
    $ printf("\nres=\n");
    $ writeln(res);
    for(i=0; i<p; i++) ans=(ans+(int64)res.a[2][i<<1|1]*(c[i]-cp[i])+(int64)res.a[2][(i+1)<<1]*cp[i])%MOD;
    printf("%d\n", ans);
    return 0;
}
