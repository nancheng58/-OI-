#include<cstdio>
#include<iostream>
using namespace std;
int a[101][101],dp[101][101];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
	    cin>>a[i][j];
	for(int i=n-1;i>=1;i--)
	  for(int j=1;j<=i;j++)
	  {
	  	a[i][j]=max((a[i][j]+a[i+1][j])%100,(a[i][j]+a[i+1][j+1])%100);
	  }
	cout<<a[1][1];
	return 0;
}
