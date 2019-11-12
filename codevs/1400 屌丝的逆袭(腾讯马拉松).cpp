#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[101][101],s[101][101],max1=-101;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		int x,y;
		memset(s,0,sizeof(s));
		if(m==0&&n==0)
		return 0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		  {
		  	cin>>g[i][j];
		  }
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		  {	  
		  	s[i][j]=g[i][j-1]+g[i+1][j]+g[i][j+1]+g[i-1][j];
		 }
		 for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		  {
		  	if(s[i][j]>max1)
		  	{
		  		max1=s[i][j];
		  		x=i;
		  		y=j;
			  }
		  }
		  cout<<x<<" "<<y<<" "<<max1<<endl;
	}
}
