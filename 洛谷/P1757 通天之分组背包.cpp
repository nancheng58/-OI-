#include<iostream>
#include<cstdio>
using namespace std;
int a[1001][1001],w[1001],v[1001],f[1001];
int main()
{
	int n,m,p;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>w[i]>>p;
		a[p][++a[p][0]]=i;
	}
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=0;j--)
	    for(int k=1;k<=a[i][0];k++)
	    {
	    	if(j>=v[a[i][k]])
	    	  {
	    	  	f[j]=max(f[j],f[j-v[a[i][k]]]+w[a[i][k]]);
			  }
		}
	cout<<f[m];
	return 0;	
}
