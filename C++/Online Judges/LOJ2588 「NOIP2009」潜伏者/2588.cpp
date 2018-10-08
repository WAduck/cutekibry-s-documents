#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length() or s1.length()<26){
        cout<<"Failed"; return 0;
    }
    char trans[26]={0};
    char stack[26]={0};
    int count=0;
    for(int i=0;i<s1.length();i++){
        if(trans[s1[i]-'A'] and trans[s1[i]-'A']!=s2[i]){
            cout<<"Failed"; return 0;
        }
        else if(!trans[s1[i]-'A']){
            for(int j=0;j<count;j++)
                if(stack[j]==s2[i]){
                    cout<<"Failed"; return 0;
                }

            stack[count]=s2[i];
            count++;
            trans[s1[i]-'A']=s2[i];
        }
    }
    if(count!=26){ cout<<"Failed"; return 0;}

    cin>>s1;
    for(int i=0;i<s1.length();i++)
        cout<<trans[s1[i]-'A'];

}
