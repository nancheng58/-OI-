#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double g[1001][1001];
int n,m;
struct data
{
	double x;
	double y;
}
a[1001];
void floyed()
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
	memset(g,100,sizeof(g));
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a[i].x>>a[i].y;
	  }
	 cin>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		g[x][y]=g[y][x]=sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
	}
	floyed();
	int u,v;
	cin>>u>>v;
	printf("%.2lf",g[u][v]);
	return 0;
}
