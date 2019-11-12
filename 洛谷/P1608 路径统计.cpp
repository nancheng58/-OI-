#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define MAXN 2000001
using namespace std;
int cut,head[MAXN],n,m,p[MAXN],tot,ans,minans;
bool b[MAXN];
struct edge{int v,next,x;}e[MAXN];
struct data{int ans,x;}dis[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
void add(int u,int v,int z)
{
	e[++cut].v=v;
	e[cut].x=z;
	e[cut].next=head[u];
	head[u]=cut;
}
void spfa1(int s)
{
	for(int i=0;i<=n;i++)  dis[i].x=1e9;
	queue<int>q;q.push(s);dis[s].x=0,dis[1].ans=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();b[u]=false;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v].x>=dis[u].x+e[i].x)
			{
				if(dis[v].x==dis[u].x+e[i].x)
				  dis[v].ans+=dis[u].ans;
				else{
					dis[v].x=dis[u].x+e[i].x;
					dis[v].ans=dis[u].ans;
				}
				if(!b[v]) b[v]=true,q.push(v);
			}
		}
	}
}
bool check(int u,int v,int z)
{
	for(int i=head[u];i;i=e[i].next)
	  if(e[i].v==v&&e[i].x==z) return false;
	return true;
}
int main()
{
	int x,y,z;
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		if(!check(x,y,z)) continue;
		add(x,y,z);
	}
	spfa1(1);minans=dis[n].x;
	if(minans==dis[0].x)
	{
		printf("No answer");return 0;
	}
	printf("%d %d",minans,dis[n].ans);
	return 0;
}
