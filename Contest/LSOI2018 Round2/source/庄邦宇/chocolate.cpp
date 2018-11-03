#include<cstdio>
#include<queue>
using namespace std;
//below
struct chocolate{
	int kind;
	int price;
	bool operator <(const chocolate &b)const
	{
		return b.price<price;
	}
} putin;
struct cnt{
	int how_many;
	int how_much;
} kind[2];
priority_queue<chocolate> a;
int n,m1,m2;
int main()
{
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d%d",&putin.kind,&putin.price);
		a.push(putin);
	}
	for(int i = 1;kind[0].how_many != m1 || kind[1].how_many != m2;i++)
	{
		chocolate k = a.top();
		a.pop();
		if(k.kind == 1 && kind[0].how_many != m1){kind[0].how_many += 1;kind[0].how_much+=k.price;}
		if(k.kind == 2 && kind[1].how_many != m2){kind[1].how_many += 1;kind[1].how_much+=k.price;}
		if(k.kind == 3)
		{
			if(kind[0].how_many != m1 && kind[0].how_many == m2){kind[0].how_many += 1;kind[0].how_much+=k.price;}
			else if(kind[0].how_many == m1 && kind[1].how_many != m2){kind[1].how_many += 1;kind[1].how_much+=k.price;}
			else
			{
			if(a.top().kind == 1 && a.top().price >= k.price){kind[0].how_many += 1;kind[0].how_much+=k.price;}
			if(a.top().kind == 2 && a.top().price >= k.price){kind[1].how_many += 1;kind[1].how_much+=k.price;}
			else{
				if(kind[0].how_many != kind[1].how_many)
				{
				kind[kind[0].how_many<kind[1].how_many?0:1].how_much += k.price;
				kind[kind[0].how_many<kind[1].how_many?0:1].how_many += 1;
			}
			else{
				kind[kind[0].how_much<kind[1].how_much?0:1].how_many += 1;
				kind[kind[0].how_much<kind[1].how_much?0:1].how_much += k.price;
			}
			}
		}
		}
	}
	printf("%d",kind[0].how_much+kind[1].how_much);
	return 0;
}
