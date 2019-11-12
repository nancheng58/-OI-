#include<iostream>
#include<cstdio>
using namespace std;
int v[101],dp[1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		dp[i]=0x7fffff;
	}
	//dp[0]=0;
	for(int i=1;i<=n;i++)
	  for(int j=i;j<=n;j++)
	  {
	  	dp[j]=min(dp[j-i]+v[i],dp[j]);
	  }
	/*for(int i=1;i<=n;i++)
	  cout<<dp[i]<<endl; */ 
	cout<<dp[n];
	return 0;  
}
