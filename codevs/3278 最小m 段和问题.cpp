#include<iostream>
#include<cstdio>
using namespace std;
int a[1001],f[1001][1001],tot=100000001,max1;
int main()
{
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i][1]=f[i-1][1]+a[i];
	}
	for(int i=2;i<=m;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	tot=100000001;
	  	for(int k=i;k<j;k++)
	  	{
	  		max1=max(f[j][1]-f[k][1],f[k][i-1]);
		  	if(tot>max1)
		  	  tot=max1;
		  }
		f[j][i]=tot;  
	   } 
	 cout<<f[n][m];
	 return 0;  
}
