#include<iostream>
using namespace std;
unsigned long long a[10001];
int main()
{
	int n;
	cin>>n;
	a[1]=0;
	a[2]=1;
	a[3]=0;
	for(int i=4;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3]+1;
	}
	cout<<a[n];
	return 0;
}
