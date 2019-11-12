#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[1001][1001],n,tot,m,k;
bool b[1001][1001];
void floyed()
{
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(g[i][j]>g[i][k]+g[k][j]&&b[i][k]&&b[k][j])
	    	  {
	    	  	g[i][j]=g[i][k]+g[k][j];
	    	  	b[i][j]=1;
	    	  }
	    }
}
int main()
{
	int x,y,z;
	
	cin>>n>>m>>k;
	memset(g,10,sizeof(g));
	for(int i=1;i<=m;i++)
	  {
	  	cin>>x>>y>>z;
	  	g[x][y]=min(g[x][y],z);
	  	b[x][y]=1;
	  }
	floyed();
	for(int i=1;i<=n;i++)
	  if(b[i][k]&&b[k][i]&&i!=k)
	    tot=max(g[i][k]+g[k][i],tot);
	cout<<tot;
	return 0;
}
