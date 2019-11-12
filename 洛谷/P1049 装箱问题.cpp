#include<iostream>
#include<cstdio>
using namespace std;
int a[31],f[21001];
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=a[i];j--)
	  {
	  	f[j]=max(f[j],f[j-a[i]]+a[i]);
	  }
	cout<<m-f[m];
	return 0;
}
