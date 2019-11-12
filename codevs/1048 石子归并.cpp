#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[1001],f[1001][1001];
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		s[i]=s[i-1]+x;
	}
	memset(f,1,sizeof(f));
	for(int i=1;i<=n;i++)
	  f[i][i]=0;
	for(int i=n-1;i>=1;i--)
	  for(int j=i+1;j<=n;j++)
	    for(int k=i;k<j;k++)
	    {
	    	f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
		}
	cout<<f[1][n];
	return 0;
}
