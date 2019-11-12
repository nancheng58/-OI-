#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 5101
using namespace std;
int n,m,g[MAXN][MAXN],u,v,dis[MAXN];
bool b[MAXN];
void dij(int u,int v)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=g[u][i];
	}
	dis[u]=0;b[u]=1;
	for(int i=2;i<=n;i++)
	{
		int max1=1000000;
		for(int j=1;j<=n;j++)
		if(!b[j]&&max1>dis[j])
		{
			u=j;
			max1=dis[j];
		}
		b[u]=1;
		for(int j=1;j<=n;j++)
		{
			if(!b[j])
			{
				dis[j]=min(dis[u]+g[u][j],dis[j]);
			}
		}
	}
}
int main()
{
	
	memset(dis,0x7f,sizeof(dis));
	int x,y,z;
	cin>>n>>m>>u>>v;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    g[i][j]=1000000;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x][y]=min(g[x][y],z);
		g[y][x]=min(g[y][x],z);
	}
	dij(u,v);
	cout<<dis[v];
	return 0;
}
