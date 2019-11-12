#include<iostream> 
#include<cstdio>
using namespace std;
char g[1600][1600];
int k,m,n,tot,min1=100000000,sum;
int dx[5]={0,1,-1,0,0},a[22501];
int dy[5]={0,0,0,1,-1},b[22501];
void bfs(int x,int y)
{
	int head=0,tail=1;
	a[head+1]=x,b[head+1]=y;
	while(head<tail)
	{
		head++;
		for(int i=1;i<=4;i++)
	{
		int xx=a[head]+dx[i],yy=b[head]+dy[i];
		if(g[xx][yy]=='*')
		{
			tail++;
			g[xx][yy]='1';
			a[tail]=xx;
			b[tail]=yy;
			tot++;
		}
	}
	}
	
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	cin>>g[i][j];
	  }
	  for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(g[i][j]=='*')
	    	  sum++;
		}
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(g[i][j]=='*')
	  	{
	  		tot=1;
			bfs(i,j);
			if(tot<min1)
			{
				min1=tot;
			}
		  }
	  }
	  int l=sum-min1;
	  if(l*3<k)
	  	cout<<"Demacia Lose!";
	    else  cout<<"Demacia Win!";
	  return 0;
}
