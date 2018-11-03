#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,m1,m2,i,s1[100001],s2[100001],s3[100001],s4[100001],s5[100001],sum=0,t1=0,t2=0,t3=0;
int main()
{
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&s1[i],&s2[i]);
		if(s1[i]==1)
		{
			t1++;
			s3[t1]=s2[i];
		}
		if(s1[i]==2)
		{
			t2++;
			s4[t2]=s2[i];
		}
		if(s1[i]==3)
		{
			t3++;
			s5[t3]=s2[i];
		}
	}
	sort(s3+1,s3+t1+1);
	sort(s4+1,s4+t2+1);
	sort(s5+1,s5+t3+1);
	i=1;
	int x1=m1,x2=m2;
	while(((s5[i]<s3[x1]&&x1>0)||(s5[i]<s4[x2]&&x2>0)||(s3[x1]==0&&x1>0)||(s4[x2]==0&&x2>0))&&i<=t3)
	{
		if(s3[x1]==0)
		{
			s3[x1]=s5[i];
			x1--;
		}
		else if(s4[x2]==0)
		{
			s4[x2]=s5[i];
			x2--;
		}
		else if(x1>0&&x2>0)
		{
			if(s5[i]<s3[x1]&&s5[i]<s4[x2])
			{
				if(s3[x1]>s4[x2])
				{
					s3[x1]=s5[i];
					x1--;
				}
				else
				{
					s4[x2]=s5[i];
					x2--;
				}
			}
			else if(s3[x1]>s5[i])
			{
				s3[x1]=s5[i];
				x1--;
			}
			else
			{
				s4[x2]=s5[i];
				x2--;
			}
		}
		else if(x1>0&&x2<=0&&s5[i]<s3[x1])
		{
			s3[x1]=s5[i];
			x1--;
		}
		else if(x1<=0&&x2>0&&s5[i]<s4[x2])
		{
			s4[x2]=s5[i];
			x2--;
		}
		++i;
	}
	for(i=1;i<=m1;++i)
	{
		sum+=s3[i];
	}
	for(i=1;i<=m2;++i)
	{
		sum+=s4[i];
	}
	printf("%d",sum);
	return 0;
}
