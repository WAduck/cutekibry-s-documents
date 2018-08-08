//  人才
// 为什么不打暴力呢，这样是基本没分的qwq
#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    cout<<random(1,100)<<' ';
    return 0;
}