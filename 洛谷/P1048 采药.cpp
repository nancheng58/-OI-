#include<iostream>
#include<cstdio>
using namespace std; 
int v[1001],c[1001],f[1001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i]>>v[i];
	}
	for(int i=1;i<=m;i++)
	  for(int j=n;j>=c[i];j--)
	  {
	  	f[j]=max(f[j],f[j-c[i]]+v[i]);
	  }
	cout<<f[n];
	return 0;
}
