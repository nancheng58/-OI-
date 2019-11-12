#include<iostream>
#include<cstdio>
using namespace std;
int f[1001][1001],a[1001],s[1001]={1};
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]*a[i];
	}
	for(int k=1;k<=m;k++)
	for(int i=k+1;i<=n;i++)
	  for(int j=k;j<i;j++)
	    
	    {
	    	f[i][k]=max(f[i][k],f[i][k-1]+(s[j+1]/s[i]));
		}
	cout<<f[n][m];
	return 0;
}
