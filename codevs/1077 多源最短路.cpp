#include<iostream>
#include<cstdio>
using namespace std;
int g[1001][1001];
int n,u,v,k;
void floyd()
{
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	cin>>g[i][j];
	  	//if(g[i][j]==0)
	  	  //g[i][j]=10000000;
	  }
	floyd();
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>u>>v;
		cout<<g[u][v];
		printf("\n");
	}
	return 0;
}
