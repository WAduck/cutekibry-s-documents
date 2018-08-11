/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <map>
using namespace std;
map<string, int> money;
int i, n, x;
int m;
string s, name[15];

int main(){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    cin>>n;
    m=n;
    for(i=1; i<=n; i++) cin>>name[i];
    while(cin>>s){
        cin>>x>>n;
        if(!n) continue;
        money[s]-=x/n*n;
        for(i=1; i<=n; i++){
            cin>>s;
            money[s]+=x/n;
        }
    }
    for(i=1; i<=m; i++)
        cout<<name[i]<<' '<<money[name[i]]<<endl;
	return 0;
}
