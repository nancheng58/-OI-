/*
最小费用最大流.
这题特殊的一点是每个点只能走一次.
然后拆点后建流量为1的边保证这个东西.
跑bfs找增广路 
增广时记下增广的路径.
然后更新流量.
直到不能增广为止.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 20010*2
#define INF 100000001
using namespace std;
int n,m,head[MAXN],ans,cut=1,tot,dis[MAXN],pre[MAXN];
bool b[MAXN];
struct data{int v,next,c,w;}e[MAXN*2];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
 	return x*f;
}
void add(int u,int v,int x,int w)
{
	e[++cut].v=v;
	e[cut].c=x;
	e[cut].w=w;
	e[cut].next=head[u];
	head[u]=cut;
}
bool bfs()
{
	for(int i=0;i<=n*2+1;i++) dis[i]=INF;
	memset(b,0,sizeof b);
	queue<int>q;
	dis[0]=0;q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();b[u]=false;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w&&e[i].c)
			{
				pre[v]=i;
				dis[v]=dis[u]+e[i].w;
				if(!b[v]) b[v]=true,q.push(v);
			}
		}
	}
	return dis[n*2+1]!=INF;
}
void dinic(int s,int t)
{
	while(t!=s)
	{
		int p=pre[t],v=e[p].v;
		e[p].c--,e[p^1].c++;
		t=e[p^1].v;
	}
	ans+=dis[n*2+1];
	return ;
}
int main()
{
	int x,y,z;
	n=read(),m=read();
	add(0,1,INF,0),add(1,0,0,0);
	add(n*2,n*2+1,INF,0),add(n*2+1,n*2,0,0);
	for(int i=2;i<n;i++) add(i,i+n,1,0),add(i+n,i,0,0);
	add(1,n+1,INF,0),add(n+1,1,0,0);
	add(n,2*n,INF,0),add(2*n,n,0,0);
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		add(x+n,y,1,z),add(y,x+n,0,-z);
	}
 	while(bfs()) {tot++;dinic(0,n*2+1);}
	printf("%d %d",tot,ans);
	return 0;
}
