#include<iostream>
using namespace std;
int main()
{
	int n,tot=0;
	cin>>n;
	while(n)
	{
		tot+=(n+1)/2;
		n/=4;
	}
	cout<<tot;
	return 0;
}
