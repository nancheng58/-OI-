#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define MAXN 31
using namespace std;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
struct data{int x,y;}s[MAXN];
queue<data>q;
int n,g[MAXN][MAXN],f[MAXN][MAXN],b[MAXN][MAXN];
void bfs(int xx,int xy)
{
	bool flag=false;int x,y,tot=0;
	s[++tot].x=xx,s[tot].y=xy;
	data u;u.x=xx,u.y=xy;q.push(u);
	while(!q.empty())
	{
		u=q.front();q.pop();
		x=u.x,y=u.y;
		if(x==n||x==1||y==n||y==1) flag=true;
		for(int i=1;i<=4;i++)
		{
			if(x+dx[i]>=1&&x+dx[i]<=n&&y+dy[i]>=1&&
			y+dy[i]<=n&&!g[x+dx[i]][y+dy[i]]&&
			  !b[x+dx[i]][y+dy[i]])
			  {
			  	data v;v.x=x+dx[i];v.y=y+dy[i];
			  	b[x+dx[i]][y+dy[i]]=true;
			  	q.push(v);
			  }
		}
	}
	if(!flag)
	{
		for(int i=1;i<=tot;i++)
		  f[s[tot].x][s[tot].y]=2;
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	scanf("%d",&g[i][j]);f[i][j]=g[i][j];
	  }
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	memset(b,0,sizeof b);
	  	if(!f[i][j]) bfs(i,j);
	  }
	  
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		  printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
	  
}
