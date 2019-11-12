/*
½ÄÐÒfloyed»¹ÊÇ±¬ÁËTLE. 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 2501
using namespace std;
int n,m,g[MAXN][MAXN],u,v;
void floyed()
{
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(i!=j&&i!=k&&j!=k)
	    	{
	    		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	    	}
	    }
}
int main()
{
	memset(g,127/3,sizeof(g));
	int x,y,z;
	cin>>n>>m>>u>>v;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x][y]=g[y][x]=z;
	}
	floyed();
	cout<<g[u][v];
	return 0;
}
