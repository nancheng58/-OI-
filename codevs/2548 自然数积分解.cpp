#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;
int a[100001],tot,s1;
int hs(int t,int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
	//for(int i=a[t-1];i<=s;i++)
		if(i>=a[t-1])
		{
			a[t]=i;
		if(n%a[t]==0)
		{
		tot++;
		s1=n/a[t];
		if(s1>1)
		  hs(t+1,s1);
		a[t]=1;
		}
		}
		  
	}
}
int main()
{
	int n;
	cin>>n;
	//a[0]=1;
	hs(1,n);
	cout<<tot+1;
	return 0;
}
