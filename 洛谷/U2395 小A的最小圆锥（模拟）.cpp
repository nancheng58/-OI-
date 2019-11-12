#include<iostream>
using namespace std;
int maxr=100000000,maxh=10000000;
int main()
{
	int n,x,y,z;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x<=maxr)
		{
			if(y<maxh)
			{
			maxr=x;
			z=i;
			maxh=y;
			}	
		}
	}
	cout<<z;
	return 0;
}
