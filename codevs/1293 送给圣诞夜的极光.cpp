#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 101
using namespace std;
//vector<int>g[MAXN];
bool  g[MAXN][MAXN];
//vector<int>f(1);
int n,m,tot;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
void bfs(int x,int y)
{
	//if(x<0||x>n-1||y<0||y>m-1||g[x][y]==0)return;
	g[x][y]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		if(g[xx][yy])
		{
			bfs(xx,yy);
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
		if(ch=='-')
		g[i][j]=0;
		//g[i].push_back(0);
		if(ch=='#')
		g[i][j]=1;
		//g[i].push_back(1);
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(g[i][j])
	  	{
	  		bfs(i,j);
	  		tot++;
		  }
	  }
	if(tot)  
	cout<<"There are "<<tot<<" ships.";
	else cout<<"Bad placement.";
	return 0;
}
