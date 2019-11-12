#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,tot=0;
	cin>>n;
	int k=n;
	while(k!=0)
	{
		k/=2;
		tot+=k;
	}
	cout<<tot<<endl;
	while(n!=0)
	{
		n/=2;
		if(n)
		cout<<n<<" ";
	}
	return 0;
}
