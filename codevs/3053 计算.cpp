#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1001],b[1001],tot;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		tot+=pow(a[i],b[i]);
	}
	cout<<tot;
	return 0;
}
