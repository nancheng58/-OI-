#include<iostream>
using namespace std;
long long a[100010000];
int main()
{
	int n;
	a[2]=3;
	a[3]=7;
	cin>>n;
	for(int i=4;i<=n;i++)
	{
		a[i]=2*a[i-1]+a[i-2]+6;
	}
	cout<<a[n];
	return 0;
}
