#include<iostream>
#include<cstdio>
using namespace std;
long long dp[101][101],x1,y1,x2,y2,m,n;
int main()
{
	int i,j;
	cin>>n>>m>>x1>>y1>>x2>>y2;
	dp[x1+2][y1+1]=1;
	dp[x1+1][y1-2]=1;
	dp[x1+1][y1+2]=1;
	dp[x1+2][y1-1]=1;
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	  {
	  	dp[i][j]=dp[i][j]+dp[i-1][j-2]+dp[i-1][j+2]+dp[i-2][j-1]+dp[i-2][j+1];//ÏòÓÒ×ßËÑ×ó±ß. 
	  }
	cout<<dp[x2][y2];
	return 0;  
}
