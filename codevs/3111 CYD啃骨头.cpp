#include<iostream>
#include<cstdio> 
using namespace std;
int v[1001],c[1001],w[1001],f[1001];
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>w[i];
	}
	  
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=0;j--)
	     {
	     	if(j-v[i]>=0)
	     	f[j]=max(f[j],f[j-v[i]]+w[i]);
		 }
	cout<<f[m];
	return 0;	 
}
