#include<iostream>
using namespace std;
int a[10001],max1,tot;
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]=1;
		max1=max(x,max1);
	}
	for(int i=1;i<=max1;i++)
	{
		if(a[i])
		  tot++;
	}
	cout<<tot<<endl;
	for(int i=1;i<=max1;i++)
	{
		if(a[i])
		  cout<<i<<" ";
	}
	return 0;
}
