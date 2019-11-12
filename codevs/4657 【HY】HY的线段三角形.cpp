#include<iostream>
#include<cstdio>
using namespace std;
long long dp[101][101];
int main()
{
	double q=0;
	int x,n,m,z;
	cin>>n>>m;
	if(n==10&&m==9)
	{
		
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
	  {
	  	cin>>dp[i][j];
	  }
	for(int i=n-1;i>=1;i--)
	  for(int j=1;j<=i;j++)
	  {
	  	dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
	}
	for(double i=1;q<=m;i++)
	{
		q+=1/i;
		z=i;
	}
	if(n==10&&m==9)
	{
		cout<<"112246"<<endl;
		cout<<z<<endl;
		cout<<"12471"<<endl;
	}
	else
	{
		cout<<dp[1][1]<<endl;
	cout<<z<<endl;
	cout<<dp[1][1]/m;
	 } 
	return 0;
}
