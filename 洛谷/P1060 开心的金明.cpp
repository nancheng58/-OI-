#include<iostream>
#include<cstdio>
using namespace std;
int v[26],p[26],f[40100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>p[i];
	}
	for(int i=1;i<=m;i++)
	  for(int j=n;j>=v[i];j--)
	  {
	  	f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
	  }
	  cout<<f[n];
	  return 0;
}
