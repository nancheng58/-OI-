#include<iostream>
#include<cstdio>
using namespace std;
int a[10101];
int main()
{
	int n,tot=0,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)//和 
	  {
	  	s=0;
	  	for(int j=1;j<=n;j++)
	    for(int k=j+1;k<=n;k++)
	    {
	    	if(a[i]==a[j]+a[k])
	    	 {
	    	 	s++;//满足条件的数 
			  if(s==1) tot++;
			  } 
		}
		
	  }
	  cout<<tot;
	  return 0;
	  dp[i][j]=max(dp[i-1][j],dp[i-1][j-vn[i]]+vn[i]);
}
