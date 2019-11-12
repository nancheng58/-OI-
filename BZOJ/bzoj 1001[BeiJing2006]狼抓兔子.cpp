/*
最小割=最大流.
然后dinic暴力m*n^2. 
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define MAXN 1000001
using namespace std;
struct data{int v,next,c;}e[MAXN*6];
int n,m,dis[MAXN],tot,ans,cut=1,head[MAXN],max1=1e9;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int u,int v,int x)
{
	e[++cut].v=v;
	e[cut].c=x;
	e[cut].next=head[u];
	head[u]=cut;
}
bool bfs()
{
	memset(dis,-1,sizeof dis);
	queue<int>q;
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]==-1&&e[i].c)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[n*m]!=-1;
}
int dfs(int u,int y)
{
	if(u==n*m) return y;
	int rest=0;
	for(int i=head[u];i&&rest<y;i=e[i].next)
	{
		int v=e[i].v;
		if(dis[v]==dis[u]+1&&e[i].c>0)
		{
			int x=min(e[i].c,y-rest);
			x=dfs(v,x);
			rest+=x;
			e[i].c-=x;
			e[i^1].c+=x;
		}
	}
	if(!rest) dis[u]=-1;
	return rest;
}
int dinic(int s,int t)
{
	while(bfs()) 
	ans+=dfs(s,max1);
	return ans;
}
int main()
{
	freopen("bjrabbit.in","r",stdin);
	freopen("bjrabbit.out","w",stdout);
	int x,y;
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m-1;j++)
	  {
		x=read();add((i-1)*m+j,(i-1)*m+j+1,x);
		add((i-1)*m+j+1,(i-1)*m+j,x);
	  }
	for(int i=1;i<=n-1;i++)
	  for(int j=1;j<=m;j++)
	  {
		x=read();add((i-1)*m+j,i*m+j,x);
		add(i*m+j,(i-1)*m+j,x);
	  }
	for(int i=1;i<=n-1;i++)
	  for(int j=1;j<=m-1;j++)
	  {
	  	x=read();
	  	add((i-1)*m+j,i*m+j+1,x);
		add(i*m+j+1,(i-1)*m+j,x);
	  }
	printf("%d",dinic(1,n*m));
	return 0;
}
