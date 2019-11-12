#include<iostream>
#include<cstdio>
using namespace std;
int a[13],tot,zh;
int main()
{
	int i=1;
	while(i!=13)
	{
		tot+=300;
		int x;
		cin>>x;
		tot-=x;
		if(tot<0)
		{
			cout<<"-"<<i;
			return 0;
		}
		while(tot>=100)
		{
			tot-=100;
			zh+=100;
		}
		i++;
	}
	cout<<tot+zh*1.2;
	return 0;
}
