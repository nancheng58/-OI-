#include<iostream>
#include<cstdio>
#define mod0 10000
#define MAXN 60001
#define MAXK 101
using namespace std;
int f[MAXN][MAXK];
int main()
{
	int n,m;
	cin>>n>>m;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(i>=j)
	  	  f[i][j]=(f[i-j][j]+f[i-1][j-1])%mod0;
	  }
	cout<<f[n][m];
	return 0; 
}
