#include<iostream>
#include<cstdio>
using namespace std;
int g[1010][1010];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
	  {
	  	cin>>g[i][j];
	  }
	for(int i=n-1;i>=1;i--)
	  for(int j=1;j<=i;j++)
	  {
	  	g[i][j]+=max(g[i+1][j],g[i+1][j+1]);
		}
	cout<<g[1][1];
	return 0;	
}
