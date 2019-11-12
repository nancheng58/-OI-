#include<iostream>
#include<cstdio> 
using namespace std;
int v[1001],c[1001],w[1001],f[1001];
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	  cin>>v[i]>>w[i]>>c[i];
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=0;j--)
	    for(int k=0;k<=c[i];k++)
	     {
	     	if(j-k*v[i]>=0)
	     	f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
		 }
	cout<<f[m];
	return 0;	 
}
