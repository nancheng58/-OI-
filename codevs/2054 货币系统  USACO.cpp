#include<iostream>
#include<cstdio>
using namespace std;
long long a[1001],dp[1001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(j>=a[i])
	  	  dp[j]+=dp[j-a[i]];
		}
	cout<<dp[m];
	return 0;
}
