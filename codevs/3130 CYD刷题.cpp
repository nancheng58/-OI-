#include<iostream>
#include<cstdio>
using namespace std;
int n,m,tot,w[1001],v[1001],mm[1001],f[1001];
int main()
{
	cin>>n>>m>>tot;
	for(int i=1;i<=n;i++)
	  cin>>w[i]>>v[i]>>mm[i];
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=v[i];j--)
	  {
	  	if(mm[i]<=tot)
	  	{
	  		f[j]=max(f[j],f[j-v[i]]+w[i]);
		  }
	   }
	cout<<f[m];
	return 0;
}
