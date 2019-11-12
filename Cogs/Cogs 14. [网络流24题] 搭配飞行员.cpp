/*
二分图匹配.
之前是用匈牙利搞的.
然后最大流
正向源点流量为1,反向为0.
正向汇点流量为1,反向为0.
*/ 
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define MAXN 10001
using namespace std;
struct data{int v,next,c;}e[MAXN*2];
int n,m,max1=1e9,ans,tot,cut=1,dis[MAXN],head[MAXN];
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
	q.push(0);
	dis[0]=0;
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
	return dis[n+1]!=-1;
}
int dfs(int u,int y)
{
	if(u==n+1) return y;
	int rest=0;
	for(int i=head[u];i&&rest<y;i=e[i].next)
	{
		int v=e[i].v;
		if(dis[v]==dis[u]+1&&e[i].c)
		{
			int x=dfs(v,min(e[i].c,y-rest));
			rest+=x;
			e[i].c-=x;
			e[i^1].c+=x;
		}
	}
	if(!rest) dis[u]=-1;
	return rest;
}
void dinic(int s,int t)
{
	while(bfs()) ans+=dfs(s,max1);
	printf("%d",ans);
	return ;
}
int main()
{
	freopen("flyer.in","r",stdin);
	freopen("flyer.out","w",stdout); 
	int x,y;
	n=read(),m=read();
	for(int i=1;i<=m;i++) add(0,i,1),add(i,0,0);
	for(int i=m+1;i<=n;i++) add(i,n+1,1),add(n+1,i,0);
	while(scanf("%d %d",&x,&y)!=EOF) add(x,y,max1),add(y,x,0);
	dinic(0,n+1);
	return 0;
}
