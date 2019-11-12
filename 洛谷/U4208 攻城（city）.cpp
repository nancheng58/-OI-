#include<iostream>
#include<cmath>
#include<cstdio>
#define mod 1000000007
#define MAXN 5001
using namespace std;
int f[MAXN][MAXN],n;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(f[n][0]) 
		{
		  printf("%d\n",f[n][0]%mod);continue;
		}
		f[0][0]=1;
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=n;j++)
	{
	  	f[i][j]=f[i-1][j+1]%mod;
	  	if(j-1>=0) f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
	  }
	printf("%d\n",f[n][0]%mod);
	}
	
	return 0;
}
