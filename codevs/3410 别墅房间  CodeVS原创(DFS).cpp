#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 2001
bool g[MAXN][MAXN];
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int n,m,tot;
int Dfs(int x,int y)
{
	g[x][y]=false;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(g[xx][yy])
		{
			Dfs(xx,yy);
		}
	}
}
int main()
{

	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	{
		cin>>ch;
		if(ch=='.')
		  g[i][j]=true;
		else g[i][j]=false;
	}	  
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(g[i][j])
	  	{
	  		tot++;
	  		Dfs(i,j);
		  }
	  }
	cout<<tot;
	return 0;  
}
