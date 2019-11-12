#include<iostream>
#include<cstdio>
using namespace std;
int n,m,w[101],v[101],f[1001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=v[i];j--)
	  {
	  	f[j]=max(f[j],f[j-v[i]]+w[i]);
	  }
	cout<<f[m];
	return 0;
}
