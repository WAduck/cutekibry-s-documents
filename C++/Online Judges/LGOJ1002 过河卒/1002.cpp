#include<iostream>
#include<cstdio>
using namespace std;
int hox,hoy,x,y;
long long n[100][100],ans[100][100];
void kk(int a,int b){
    n[hox][hoy]=1;
    n[hox-2][hoy-1]=1;
    n[hox-2][hoy+1]=1;
    n[hox-1][hoy-2]=1;
    n[hox-1][hoy+2]=1;
    n[hox+2][hoy-1]=1;
    n[hox+2][hoy+1]=1;
    n[hox+1][hoy-2]=1;
    n[hox+1][hoy+2]=1;
}
int main(){
    cin>>x>>y>>hox>>hoy;
    kk(hox,hoy);
    for(int i=x;i>=0;i--)
        for(int j=y;j>=0;j--){
            if(i==x and j==y){
                ans[i][j]=1;
                continue;
            }
            if(n[i][j]==0)
                ans[i][j]=ans[i+1][j]+ans[i][j+1];
        }
    cout<<ans[0][0];
    return 0;
}
