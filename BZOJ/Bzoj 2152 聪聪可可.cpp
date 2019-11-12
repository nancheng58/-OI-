/*
点分治模板题...
处理模3意义下的点对的贡献.
贡献是t[0]*(t[0]-1)+t[1]*t[2]*2+t[0]
即t[0]*t[0]+t[1]*t[2]*2.
一开始看这题发现暴力可做啊(用人工栈2333.
*/
#include<iostream>
#include<cstdio>
#define MAXN 20001
using namespace std;
int n,k,tot,ans,g,cut,f[MAXN],sum,root,dis[MAXN],maxsize,a[MAXN],head[MAXN],deep[11],size[MAXN];
bool b[MAXN];
struct edge{int v,next,x;}e[MAXN*2];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int u,int v,int x)
{
	e[++cut].v=v;e[cut].x=x;e[cut].next=head[u];head[u]=cut;
}
void get_root(int u,int fa)
{
	size[u]=1;f[u]=0;
	for(int i=head[u];i;i=e[i].next)
	{
		if(e[i].v==fa||b[e[i].v]) continue;
		get_root(e[i].v,u);
		size[u]+=size[e[i].v];
		f[u]=max(f[u],size[e[i].v]);
	}
	f[u]=max(f[u],sum-size[u]);
	if(f[u]<f[root]) root=u;
	return ;
}
void get_deep(int u,int fa,int d)
{
	for(int i=head[u];i;i=e[i].next)
	{
		if(e[i].v==fa||b[e[i].v]) continue;
		deep[(e[i].x+d)%3]++;
		get_deep(e[i].v,u,(e[i].x+d)%3);
	}
	return ;
}
int get(int u,int d)
{
	deep[0]=deep[1]=deep[2]=0;
	deep[d]++;get_deep(u,0,d);
	return deep[0]*deep[0]+deep[1]*deep[2]*2;
}
void slove(int u)
{
	b[u]=true;ans+=get(u,0);
	for(int i=head[u];i;i=e[i].next)
	{
		if(b[e[i].v]) continue;
		ans-=get(e[i].v,e[i].x);
		sum=size[e[i].v];
		root=0;
		get_root(e[i].v,root);
		slove(root);
	}
	return ;
}
int gcd(int x,int y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
int main()
{
	int x,y,z;
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read(),y=read(),z=read();z%=3;
		add(x,y,z),add(y,x,z);
	}
	sum=n;f[0]=1e9;
	get_root(1,root);
	slove(root);
	g=gcd(ans,n*n);
	printf("%d/%d",ans/g,n*n/g);
	return 0;
}
