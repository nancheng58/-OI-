#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool g[17][17],flag;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int t,n,ux,uy,vx,vy;
void dfs(int x,int y)
{
	g[x][y]=0;
	if(x==vx&&y==vy)
	{
		flag=1;
		cout<<"YES";
		printf("\n");
		return;
	}
	for(int i=1;i<=4;i++)
	{
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		if(g[xx][yy])
		{
			dfs(xx,yy);
		}
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(g,0,sizeof(g));
		flag=0;
		cin>>n;
		char ch;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		{
			cin>>ch;
			if(ch=='.')
			  g[i][j]=1;
			if(ch=='s')
			{
				ux=i;
				uy=j;
				g[i][j]=1;
			}
			if(ch=='e')
			{
				vx=i;
				vy=j;
				g[i][j]=1;
			}
		}
		dfs(ux,uy);
		if(!flag)
		{
			cout<<"NO";
			printf("\n");
		}
	}
	return 0;
}
