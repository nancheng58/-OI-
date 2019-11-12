#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXN 1001
using namespace std;
int n,x1,y1,x2,y2,tot,ans=10000001;
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
struct data
{
	int x;
	int y;
	int tot;
}
q[MAXN*MAXN];
bool g[MAXN][MAXN];
void bfs(int x,int y)
{
	int head=0,tail=1;
	q[1].x=x;
	q[1].y=y;
	q[1].tot=0;
	while(head<tail)
	{
	head++;
	for(int i=1;i<=4;i++)
	{
		int xx=q[head].x+dx[i],yy=q[head].y+dy[i];
		if(xx<=0||xx>n||yy<=0||yy>n)continue;
		if(g[xx][yy])
		{
			tail++;
			g[xx][yy]=0;
			q[tail].x=xx;
			q[tail].y=yy;
			q[tail].tot=q[head].tot+1;
		}
		if(xx==1&&yy==n)
	{
		ans=min(ans,q[tail].tot);
	}
	}
	}
	cout<<ans;
}
int main()
{
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	q[i*j].tot=0;
	  	cin>>x;
	  	if(!x) g[i][j]=1;
	  }
	bfs(n,1);
	return 0;  
}
