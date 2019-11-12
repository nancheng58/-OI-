#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1001][1001];
int s1[101],s2[101];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>s1[i];
	for(int i=1;i<=n;i++)
	  cin>>s2[i];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(s1[i]==s2[j])
	  	  f[i][j]=f[i-1][j-1]+1;
	  	else f[i][j]=max(f[i-1][j],f[i][j-1]);
	  }
	 /*for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    cout<<f[i][j]<<" "; */
	cout<<f[n][n]<<endl;
	return 0;  
}
