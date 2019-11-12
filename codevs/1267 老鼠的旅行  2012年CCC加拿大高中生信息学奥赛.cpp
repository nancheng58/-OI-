#include<iostream>
#include<cstdio>
using namespace std;
int a[1001][1001];
bool b[1000][1001];
int main()
{
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	b[i][j]=1;
	  }
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		b[x][y]=0;
	}
	if(b[2][1])
	a[2][1]=1;
	if(b[1][2])
	a[1][2]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(
		  b[i][j])
	  	a[i][j]+=a[i-1][j]+a[i][j-1];
	  }
	  cout<<a[n][m];
	  return 0;
}
