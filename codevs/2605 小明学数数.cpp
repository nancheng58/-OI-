#include<iostream>
using namespace std;
int a[1000001],max1;
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
		if(x>max1)
		  max1=x;
	}
	for(int i=1;i<=max1;i++)
	{
		if(a[i]==1)
		  {
		  	cout<<i;
		  	return 0;
		  }
	}
}

