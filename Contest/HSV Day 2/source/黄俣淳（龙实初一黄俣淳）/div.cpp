#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t,i;
    scanf("%d", &t);
    float c[t];
    int a[t],b[t];
    for(i=0;i<t;i++) {
        scanf("%d%d",&a[i],&b[i]);
        c[i]=1.0*a[i]/b[i];
    }
    for(i=0;i<t;i++){
    printf("%d/%d=%.3f\n",a[i],b[i],c[i]); 
}
    return 0;
}