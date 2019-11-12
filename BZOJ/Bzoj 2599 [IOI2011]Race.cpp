/*
点分治.
ans[i]表示i条边权值之和为k的方案数.
然后点分治乱搞(然而我调了半个下午.
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAXN 200001
using namespace std;
int n,m,root,k,f[MAXN],total,dis[MAXN],dist[MAXN],t[MAXN],c[MAXN],ans[MAXN],tot,a[MAXN],sum,cut,head[MAXN],size[MAXN];
bool b[MAXN];
struct edge{int v,x,next;}e[MAXN*2];
struct data{int x,t;}s[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int u,int v,int x)
{
	e[++cut].v=v;e[cut].next=head[u];e[cut].x=x;head[u]=cut;
}
bool cmp(const data &x,const data &y)
{
	return x.x<y.x;
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
void get_dis(int u,int fa)
{
	total++;s[++tot].x=dis[u],s[tot].t=dist[u];
	for(int i=head[u];i;i=e[i].next)
	{
		if(e[i].v==fa||b[e[i].v]) continue;
		dis[e[i].v]=dis[u]+e[i].x;
		dist[e[i].v]=dist[u]+1;
		get_dis(e[i].v,u);
	}
	return ;
}
void erfen(int l,int r,int z)
{
	int total=0;
	sort(s+1,s+tot+1,cmp);// 1 W.
	s[0].x=1e9;
	for(int i=1;i<=tot;i++) c[i]=0;
	for(int i=1;i<=tot;i++)
	 if(s[i].x==s[i-1].x) c[total]++;
	 else a[++total]=s[i].x,t[total]=s[i].t,c[total]++;
	r=total;
	while(l<=r)
	{
		if(a[l]+a[l]==k) ans[t[l]+t[l]]+=z*(c[l]*(c[l]-1))/2;
		if(a[r]+a[r]==k) ans[t[r]+t[r]]+=z*(c[r]*(c[r]-1))/2;
		if(l==r) break;
		if(a[l]+a[r]==k) ans[t[l]+t[r]]+=z*c[l]*c[r],l++;
		else if(a[l]+a[r]<k) l++;
		else r--;
	}
	return ;
}
void Go(int u,int d,int t,int flag)
{
	dis[u]=d;dist[u]=t;tot=0;
	get_dis(u,u);
	erfen(1,tot,flag);
	return ;
}
void slove(int u)
{
	b[u]=true;Go(u,0,0,1);
	for(int i=head[u];i;i=e[i].next)
	{
		if(b[e[i].v]) continue;
		Go(e[i].v,e[i].x,1,-1);
		root=0;sum=size[e[i].v];
		get_root(e[i].v,root);
		slove(root);
	}
	return ;
}
int main()
{
	int x,y,z;
	n=read(),k=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read(),y=read(),z=read();
		x++,y++;
		add(x,y,z),add(y,x,z);
	}
	f[0]=1e9;sum=n;
	get_root(1,root);
	slove(root);
	for(int i=1;i<=n;i++) if(ans[i]) {printf("%d",i);return 0;}
	printf("-1");
	return 0;
}
