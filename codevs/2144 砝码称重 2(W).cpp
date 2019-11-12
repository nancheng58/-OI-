#include<iostream>
#include<cstdio>
#define MAXN 1001
using namespace std;
int m,n,w[MAXN],f[MAXN][MAXN];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>w[i];
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=w[i];j--)
	  {
	  	f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
	  }
	  for(int i=1;i<=n;i++)
	  
	  { for(int j=1;j<=m;j++)
	  	cout<<f[i][j]<<" ";
	  	cout<<endl;
	  }
	for(int i=1;i<=n;i++)
	  {
	  	if(f[i][m]==m)
	  	{
	  		cout<<i;
	  		return 0;
	  	}
	  }  
}

