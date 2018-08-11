/*
ID: Tsukimaru Oshawott
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
using namespace std;
const char *KEYPAD="       ABCDEFGHIJKLMNOPRSTUVWXY";
int n;
bool flag;
set<string> dict;
string a;
inline void prepare(){
}
void dfs(int p, string s){
    if(p>=n){
        dict.insert(s);
        // cout<<s<<endl;
        return;
    }
    for(int i=1; i<=3; i++) dfs(p+1, s+KEYPAD[(a[p]&15)*3+i]);
}
int main(){
    cin>>a;
    n=a.length();
    dfs(0, "");
    string s;
    while(cin>>s) if(dict.count(s)) cout<<s<<endl, flag=1; 
    if(!flag) cout<<"NONE"<<endl;
    return 0;
}
