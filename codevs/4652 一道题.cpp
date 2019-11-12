#include<iostream>
#include<cstdio>
using namespace std;
int a[101][101],g[101][101];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    cin>>a[i][j];
	for(int i=2;i<=n-1;i++)
	  for(int j=2;j<=m-1;j++)
	  {
	  	g[i][j]=(a[i][j]+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1])/5;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
	  {
	  	if(!g[i][j]) cout<<a[i][j]<<" ";
	  	else
	  	cout<<g[i][j]<<" ";
	  }
	  printf("\n");
	}
	return 0;
	  
}
