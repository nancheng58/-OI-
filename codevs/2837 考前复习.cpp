#include<iostream>
#include<cstdio>
using namespace std;
int n,m,w[5001],v[5001],f[10001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=v[i];j--)
	  {
	  	f[j]=max(f[j],f[j-v[i]]+w[i]);
	  }  
	cout<<f[m];
	return 0;  
}
