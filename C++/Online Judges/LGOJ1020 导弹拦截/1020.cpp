#include <cstdio>
#define max(_a,_b) ((_a>_b)?(_a):(_b))
using namespace std;

const int INF=100000;
int a[100];
int b[100];
int sys[101];

int main(){
    int i, j;
    int n=0;
    int ans1=1, ans2=0;
    int maxmin=0;

    sys[100]=INF;

    //scanf("%d", &n);
    //for(i=0; i<n; i++)
        //scanf("%d", &a[i][0]);

    while(scanf("%d", &a[n])==1)
        n++;

    //#1:DP
    for(i=n-1; i>=0; i--){
        for(j=i+1; j<n; j++){
            if(a[i]>a[j])
                b[i]=max(b[i], b[j]);
        }
        b[i]++;
        ans1=max(b[i], ans1);
    }

    //#2:贪心
    for(i=0; i<n; i++){
    	maxmin=100;
        for(j=0; j<ans2; j++)
        	if(sys[j]>=a[i] and sys[maxmin]>sys[j])
        		maxmin=j;
        if(maxmin==100){
        	sys[ans2]=a[i];
        	ans2++;
		}
		else
			sys[maxmin]=a[i];
    }

    printf("%d\n%d", ans1, ans2);
    return 0;
}
