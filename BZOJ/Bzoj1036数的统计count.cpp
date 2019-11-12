/*
树链剖分模板题.
套线段树
单点修改,区间查询sum,max. 
*/
#include<iostream>
#include<cstdio>
#define MAXN 300001
using namespace std;
int pos[MAXN],tot,son[MAXN],top[MAXN],size[MAXN],deep[MAXN],fa[MAXN];
int head[MAXN],a[MAXN],n,m,cut,maxsize;
struct data{int l,r,sum,lc,rc,max;}tree[MAXN*4];
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
	e[++cut].v=v;
	e[cut].next=head[u];
	head[u]=cut;
}
void build(int l,int r)
{
	int k=++cut;
	tree[k].l=l,tree[k].r=r;
	if(l==r) {tree[k].sum=tree[k].max=0;return ;}
	int mid=(l+r)>>1;
	tree[k].lc=cut+1;build(l,mid);
	tree[k].rc=cut+1;build(mid+1,r);
}
void dfs1(int u)
{
	size[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(fa[u]==v) continue;
		deep[v]=deep[u]+1;
		fa[v]=u;dfs1(v);
		size[u]+=size[v];
	}
	return ;
}
void dfs2(int u,int top1)
{
	int k=0;maxsize++;
	pos[u]=maxsize;top[u]=top1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(deep[v]>deep[u]&&size[v]>size[k]) k=v;
	}
	if(!k) return ;
	dfs2(k,top1);
	for(int i=head[u];i;i=e[i].next)
	  if(deep[e[i].v]>deep[u]&&e[i].v!=k) dfs2(e[i].v,e[i].v);
	return ;
}
void change(int k,int x,int val)
{
	if(tree[k].l==tree[k].r) {tree[k].sum=tree[k].max=val;return ;}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid) change(tree[k].lc,x,val);
	else if(x>mid) change(tree[k].rc,x,val);
	tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum;
	tree[k].max=max(tree[tree[k].lc].max,tree[tree[k].rc].max);
}
int querysum(int k,int l,int r)
{
	if(l<=tree[k].l&&tree[k].r<=r) return tree[k].sum;
	int mid=(tree[k].l+tree[k].r)>>1,total=0;
	if(l<=mid) total+=querysum(tree[k].lc,l,r);
	if(r>mid) total+=querysum(tree[k].rc,l,r);
	return total;
}
int querymax(int k,int l,int r)
{
	if(l<=tree[k].l&&tree[k].r<=r) return tree[k].max;
	int mid=(tree[k].l+tree[k].r)>>1,total=-1e9;
	if(l<=mid) total=max(total,querymax(tree[k].lc,l,r));
	if(r>mid) total=max(total,querymax(tree[k].rc,l,r));
	return total;
}
int slovesum(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		ans+=querysum(1,pos[top[x]],pos[x]);
		x=fa[top[x]];
	}
	if(pos[x]>pos[y]) swap(x,y);
	ans+=querysum(1,pos[x],pos[y]);
	return ans;
}
int slovemax(int x,int y)
{
	int ans=-1e9;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		ans=max(ans,querymax(1,pos[top[x]],pos[x]));
		x=fa[top[x]];
	}
	if(pos[x]>pos[y]) swap(x,y);
	ans=max(ans,querymax(1,pos[x],pos[y]));
	return ans;
}
int main()
{
	freopen("bzoj_1036.in","r",stdin);
	freopen("bzoj_1036.out","w",stdout);
	int x,y;
	n=read();
	for(int i=1;i<n;i++) x=read(),y=read(),add(x,y),add(y,x);
	for(int i=1;i<=n;i++) a[i]=read();
	dfs1(1),dfs2(1,1);
	cut=0;build(1,maxsize);
	for(int i=1;i<=n;i++) change(1,pos[i],a[i]);
	m=read();char ch[11];
	while(m--)
	{
		scanf("%s",ch);
		scanf("%d%d",&x,&y);
		if(ch[0]=='C') a[x]=y,change(1,pos[x],y);
		else {
			if(ch[1]=='M') printf("%d\n",slovemax(x,y));
			else printf("%d\n",slovesum(x,y));
		}
	}
	return 0;
}
