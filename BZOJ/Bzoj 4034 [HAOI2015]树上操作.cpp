/*
树链剖分裸题.
竟然不是1A.
线段树区间更新打错了...
生无可恋.... 
*/
#include<iostream>
#include<cstdio>
#define MAXN 100001
#define LL long long
using namespace std;
int n,m,a[MAXN],maxsize,tot,cut,head[MAXN];
int pos[MAXN],end[MAXN],top[MAXN],deep[MAXN],fa[MAXN],son[MAXN],size[MAXN];
struct data{int l,r,lc,rc,size;LL sum,bj;}tree[MAXN*4];
struct edge{int v,next;}e[MAXN*2];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int u,int v)
{
	e[++cut].v=v;e[cut].next=head[u];head[u]=cut;
}
void build(int l,int r)
{
	int k=++tot;
	tree[k].l=l,tree[k].r=r;tree[k].size=r-l+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	tree[k].lc=tot+1;build(l,mid);
	tree[k].rc=tot+1;build(mid+1,r);
	return ;
}
void dfs1(int u)
{
	size[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!fa[v]) fa[v]=u,deep[v]=deep[u]+1,dfs1(v),size[u]+=size[v];
	}
	return ;
}
void dfs2(int u,int top1)
{
	int k=0;top[u]=top1;pos[u]=end[u]=++maxsize;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(fa[v]==u&&size[v]>size[k]) k=v;
	}
	if(!k) return ;
	dfs2(k,top1);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(fa[v]==u&&v!=k) dfs2(v,v);
	}
	end[u]=maxsize;return ;
}
void push(int k)
{
	tree[tree[k].lc].bj+=tree[k].bj;
	tree[tree[k].rc].bj+=tree[k].bj;
	tree[tree[k].lc].sum+=(LL)tree[tree[k].lc].size*tree[k].bj;
	tree[tree[k].rc].sum+=(LL)tree[tree[k].rc].size*tree[k].bj;
	tree[k].bj=0;return ;
}
void change(int k,int l,int r,int z)
{
	if(l<=tree[k].l&&tree[k].r<=r) {
		tree[k].bj+=z,tree[k].sum+=(LL)z*tree[k].size;//1 w.
		return ;
	}
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(l<=mid) change(tree[k].lc,l,r,z);
	if(r>mid) change(tree[k].rc,l,r,z);
	tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum;
	return ;
}
LL query(int k,int l,int r)
{
	if(l<=tree[k].l&&tree[k].r<=r) return tree[k].sum;
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1;LL total=0;
	if(l<=mid) total+=query(tree[k].lc,l,r);
	if(r>mid) total+=query(tree[k].rc,l,r);
	return total;
}
void slovequery(int x)
{
	LL ans=0;
	while(top[x]!=1){
		ans+=query(1,pos[top[x]],pos[x]);
		x=fa[top[x]];
	}
	ans+=query(1,pos[1],pos[x]);
	printf("%lld\n",ans);return ;
}
int main()
{
	freopen("haoi2015_t2.in","r",stdin);
	freopen("haoi2015_t2.out","w",stdout);
	int x,y,z;
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	fa[1]=1;dfs1(1),dfs2(1,1);build(1,n);
	for(int i=1;i<=n;i++) change(1,pos[i],pos[i],a[i]);
	while(m--)
	{
		z=read();
		if(z==1) x=read(),y=read(),change(1,pos[x],pos[x],y);
		else if(z==2) x=read(),y=read(),change(1,pos[x],end[x],y);
		else x=read(),slovequery(x);
	}
	return 0;
}
