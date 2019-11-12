#include<iostream>
#include<cstdio>
using namespace std;
int v[101000],f[100001],c[100001];
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=c[i];j<=m;j++)
	  {
	  	f[j]=max(f[j],f[j-c[i]]+v[i]);
	  }
	cout<<f[m];
	return 0;  
}
