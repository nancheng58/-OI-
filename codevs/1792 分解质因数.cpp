#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,tot;
bool jd(int x)
{
	for(int i=2;i<=tot;i++)
	{
		if(tot%i==0)
		{   if(tot/i==1)
			{
				cout<<i;
				exit(0);
			}
			else
			{
			tot/=i;
			cout<<i<<"*";
			return 0;
			}
			
		}
		 
	}
}
int main()
{
	cin>>n;
	tot=n;
	cout<<tot<<"=";
	for(int i=1;i<=n;i++)
	{
		jd(i);
	}
	return 0;
}
