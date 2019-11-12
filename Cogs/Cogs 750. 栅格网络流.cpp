/*
平面图转对偶图.
最小割转最短路. 
平面图:一个图G=(V,E),若能将其画在平面上,且任意两条边的交点只能是G的顶点
对偶图中的环与平面图中的割一一对应. 
这题是有向边 大体做法就是将边统一顺时针旋转90度.
然后将外部面上的点与S,T连接.
然后这题要开unsigned long long.
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define MAXN 10111
#define INF 1e17
#define LL unsigned long long
using namespace std;
int n,m,cut,ans,head[MAXN],S,T,b[MAXN];;
LL dis[MAXN];
struct data{int v,next;LL c;}e[MAXN*8];
queue<int>q;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int u,int v,int c)
{
	e[++cut].v=v;e[cut].c=c;e[cut].next=head[u];head[u]=cut;
}
int slove(int x,int y)
{
	return (x-1)*(m+1)+y;
}
void spfa(int t)
{
	for(int i=S;i<=T;i++) dis[i]=INF;dis[S]=0;q.push(S);
	while(!q.empty())
	{
		int u=q.front();q.pop();b[u]=false;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].c)
			{
				dis[v]=dis[u]+e[i].c;
				if(b[v]!=t) b[v]=t,q.push(v);
			}
		}
	}
	return ;
}
void Clear()
{
	memset(head,0,sizeof head);
	cut=0;
	return ;
}
int main()
{
	freopen("flowa.in","r",stdin);
	freopen("flowa.out","w",stdout);
	int t,x;t=read();
	while(t--)
	{
		Clear();
		n=read(),m=read();
		S=0,T=(n+1)*(m+1)+1;
		for(int i=1;i<=n;i++)
		  for(int j=2;j<=m;j++)
		  {
		  	 x=read();
		  	 add(slove(i,j),slove(i+1,j),x);
		  	 add(slove(i+1,j),slove(i,j),x);
		  }
		for(int i=2;i<=n;i++)
		  for(int j=1;j<=m;j++)
		  {
		  	 x=read();
		  	 add(slove(i,j),slove(i,j+1),x);
		  	 add(slove(i,j+1),slove(i,j),x);
		  }
		for(int i=2;i<=m;i++) add(S,i,0);
		for(int i=2*(m+1);i<=T-2;i+=(m+1)) add(S,i,0);
		for(int i=m+2;i<=T-2;i+=(m+1)) add(i,T,0);
		for(int i=n*(m+1)+2;i<=T-2;i++) add(i,T,0);
		spfa(t+1);cout<<dis[T]<<endl;
	}
	return 0;
}
