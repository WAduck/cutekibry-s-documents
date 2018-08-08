#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int c;
    float t,a,b;
    cin>>c;
    for(int i=1;i<=c;i++)
    {
        cin>>a>>b;
        t=a/b;
        cout<<a<<"/"<<b<<"="<<fixed<<setprecision(3)<<showpoint<<t;
    }
    return 0;
}
