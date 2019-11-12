#include<iostream>
using namespace std;
int c2,c5,e=1;
int main()
{
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		int t=i;
		while(t%10==0) t/=10;//去因子
		while(t%2==0) 
		{
			c2++;
			t/=2;//去因子 
		}
		while(t%5==0)
		{
			c5++;
			t/=5;//去因子 
		 } 
		e*=t;
		e%=10; 
	}
	if(c2>c5)
	{
		for(i=1;i<=c2-c5;i++)
		{
			e*=2;
			e%=10;
		}
	}
	else 
	{
		for(i=1;i<=c5-c2;i++)
		{
			e*=5;
			e%=10;
		}
	}
	cout<<e;
	return 0;
}
