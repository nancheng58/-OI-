#include<iostream>
#include<cstdio>
#define r  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
using namespace std;
int a[101][101],b[101][101],c[101][101];
int main()
{
	int n,m;
	cin>>n>>m;
	r
	cin>>a[i][j];
	r
	cin>>b[i][j];
	r
	c[i][j]=a[i][j]+b[i][j];
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=m;j++)
	    cout<<c[i][j]<<" ";
	  printf("\n");
	}
	return 0;
}
