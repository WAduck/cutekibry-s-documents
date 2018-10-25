#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string c[1000];
string a[1000];
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int j=1;j<=q;j++)
    {
        int len;
        cin>>len;
        cin>>a[j];
        int pd=0;
        for(int i=1;i<=n;i++)
        {
            if(a[j]==c[i])
            {
                c[i]="-1";
                cout<<"1"<<endl;
                pd=1;
                break;
            }
        }
        if(pd==0)cout<<"0"<<endl;
    }
    return 0;
}