#include<iostream>
#include<cstdio>
using namespace std;
int v[5001],w[5001],m,n,tot,a[5001],f[5001];
int main()
{
	int z,y,x;
	cin>>z>>y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		a[i]=x*(y/z);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		v[i]=a[x];
		w[i]=y;
	}
	cin>>tot;
	for(int i=1;i<=n;i++)
	  for(int j=tot;j>=v[i];j--)
	  {
	  	f[j]=max(f[j],f[j-v[i]]+w[i]);
	  }
	cout<<f[tot];
	return 0;
}
