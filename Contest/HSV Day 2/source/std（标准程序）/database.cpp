#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream> 
using namespace std;
struct OIer{
    string a[5];
    OIer operator = (OIer b){
        a[1]=b.a[1];
        a[2]=b.a[2];
        a[3]=b.a[3];
        a[4]=b.a[4];
        return *this;
    }
    bool operator == (OIer b){
        int i;
        for(i=1; i<=4; i++) if(a[i]!=b.a[i]) return false;
        return true;
    }
};
OIer a[50005], c[50005];
int i, j, n;
bool cmp(OIer a, OIer b){
    int i;
    for(i=1; i<=4; i++) if(a.a[i]!=b.a[i]) return a.a[i]<b.a[i];
    return false;
}
int main(){
    scanf("%d", &n);
    for(i=1; i<=n; i++) for(j=1; j<=4; j++)
        cin>>a[i].a[j];
    for(i=0; i<=4; i++){
        for(j=1; j<=n; j++){
            c[j]=a[j];
            c[j].a[i]=" ";
        }
        sort(c+1, c+1+n, cmp);
        printf("%d ", unique(c+1, c+1+n)-c-1);
    }
    return 0;
} 