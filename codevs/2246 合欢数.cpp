#include<iostream>
using namespace std;
int main()
{
	int n,x; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;;j++)
		{
			if((x+j)%10==0)
			{
				cout<<j<<" ";break;
			}
		}
	}
	return 0;
}
