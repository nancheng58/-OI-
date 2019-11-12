#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INF 999999
#define MAXN 110
using namespace std;
int x[11],g[MAXN][MAXN],m,n,t,k,tot,y[11];
int x1,x2,y1,y2;
void build()
{
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(i>1) g[(j-1)*n+i][(j-1)*n+i-1]=x[i]-x[i-1];
	  	if(i<n) g[(j-1)*n+i][(j-1)*n+i+1]=x[i+1]-x[i];
	  	if(j>1) g[(j-1)*n+i][(j-2)*n+i]=y[j]-y[j-1];
	  	if(j<m) g[(j-1)*n+i][j*n+i]=y[j+1]-y[j];
	  }
	for(int i=1;i<=t;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		g[(y1-1)*n+x1][(y2-1)*n+x2]=INF;
		g[(y2-1)*n+x2][(y1-1)*n+x1]=INF;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x1>>x2>>y1>>y2;
		for(int j=x1;j<x2;j++)
		  for(int k=y1+1;k<y2;k++)
		  {
		  	g[(k-1)*n+j][(k-1)*n+j+1]=INF;
		  	g[(k-1)*n+j+1][(k-1)*n+j]=INF;
		  }
		for(int k=y1;k<y2;k++)
		  for(int j=x1+1;j<x2;j++)
		  {
		  	g[(k-1)*n+j][k*n+j]=INF;
		  	g[k*n+j][(k-1)*n+j]=INF;
		  }  
	}
}
void floyed()
{
	for(int l=1;l<=tot;l++)
	  for(int i=1;i<=tot;i++)
	    for(int j=1;j<=tot;j++)
	    {
	    	g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
	    }
}
int main()
{
	memset(g,1,sizeof(g));
	cin>>n>>m>>t>>k;
	tot=m*n;
	for(int i=1;i<=n*m;i++)
	  g[i][i]=0;
	for(int i=1;i<=n;i++)
	  cin>>x[i];
	for(int i=1;i<=m;i++)
	  cin>>y[i];
	build();
	floyed();
	cin>>x1>>y1>>x2>>y2;
	cout<<g[(y1-1)*n+x1][(y2-1)*n+x2];
	return 0;
}
