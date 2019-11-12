#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[1001],f[1001][1001],d[1001][1001],min1=100000000,max1,a[1001];
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		s[i+n]=s[i];
	}
	for(int i=n+1;i<=2*n;i++)
	  s[i]=s[i-1]+a[i-n];
	memset(f,10,sizeof(f));
	//memset(d,0,sizeof(d));
	for(int i=1;i<=2*n;i++)
	  	f[i][i]=0;
	for(int i=2*n;i>=1;i--)
	  for(int j=i+1;j<=2*n;j++)
	  {
	  	for(int k=i;k<j;k++)
	    {
	    	f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
	    	d[i][j]=max(d[i][j],d[i][k]+d[k+1][j]+s[j]-s[i-1]);
		}
		if(j-i+1==n)
		{
			min1=min(min1,f[i][j]);
			max1=max(max1,d[i][j]);
		}
	  } 
	cout<<min1<<endl<<max1;
	return 0;
}
