#include<iostream>
#include<cstdio>
using namespace std;
int f[45001],a[501];
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=a[i];j--)
	    f[j]=max(f[j],f[j-a[i]]+a[i]);
	cout<<f[m];
	return 0;    
}
