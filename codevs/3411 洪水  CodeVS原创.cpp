#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INFF 1000001
using namespace std;
int n,m,tot=1;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
bool b[1001][1001];
int g[1001][1001],x1,y1;
void bfs(int x,int y)
{
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(yy>=1&&xx>=1&&g[xx][yy]<=g[x][y]&&!b[xx][yy]&&yy<=m&&xx<=n)
		{
			b[xx][yy]=1;
			tot++;
			bfs(xx,yy);	
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    cin>>g[i][j];
	 //memset(g,1,sizeof(g));   
	cin>>x1>>y1;
	b[x1][y1]=1;
	bfs(x1,y1);
	cout<<n*m-tot;
	return 0;  
} 
