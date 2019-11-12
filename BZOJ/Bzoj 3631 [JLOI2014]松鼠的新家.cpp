/*
ÂãÊ÷ÆÊ.
*/
#include<iostream>
#include<cstdio>
#define MAXN 300001
using namespace std;
int n,m,tot,cut,maxsize,head[MAXN],a[MAXN],s[MAXN];
int size[MAXN],pos[MAXN],top[MAXN],fa[MAXN],deep[MAXN];
struct data{int l,r,lc,rc,sum,bj,size;}tree[MAXN<<2];
struct edge{int v,next;}e[MAXN<<1];
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
	tree[k].l=l,tree[k].r=r,tree[k].size=r-l+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	tree[k].lc=tot+1;build(l,mid);
	tree[k].rc=tot+1;build(mid+1,r);
	return ;
}
void push(int k)
{
	tree[tree[k].lc].bj+=tree[k].bj;
	tree[tree[k].rc].bj+=tree[k].bj;
	tree[tree[k].lc].sum+=tree[tree[k].lc].size*tree[k].bj;
	tree[tree[k].rc].sum+=tree[tree[k].rc].size*tree[k].bj;
	tree[k].bj=0;return ;
}
void change(int k,int l,int r,int z)
{
	if(l<=tree[k].l&&tree[k].r<=r) {
		tree[k].bj+=z;tree[k].sum+=z*tree[k].size;
		return ;
	}
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(l<=mid) change(tree[k].lc,l,r,z);
	if(r>mid) change(tree[k].rc,l,r,z);
	tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum;
	return ;
}
int query(int k,int l,int r)
{
	if(l<=tree[k].l&&tree[k].r<=r) return tree[k].sum;
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1,total=0;
	if(l<=mid) total+=query(tree[k].lc,l,r);
	if(r>mid) total+=query(tree[k].rc,l,r);
	return total;
}
void slove(int k,int l,int r)
{
	if(l==r){s[l]=tree[k].sum;return ;}
	if(tree[k].bj) push(k);
	int mid=(l+r)>>1;
	slove(tree[k].lc,l,mid),slove(tree[k].rc,mid+1,r);
	return;
}
void dfs1(int u)
{
	size[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!fa[v]) fa[v]=u,deep[v]=deep[u]+1,dfs1(v),size[v]+=size[u];
	}
	return ;
}
void dfs2(int u,int top1)
{
	int k=0;pos[u]=++maxsize;top[u]=top1;
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
	return ;
}
void slovechange(int x,int y)
{
	change(1,pos[y],pos[y],-1);
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		change(1,pos[top[x]],pos[x],1);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	change(1,pos[x],pos[y],1);return ;
}
int main()
{
	int x,y;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n-1;i++) x=read(),y=read(),add(x,y),add(y,x);
	fa[1]=1;dfs1(1),dfs2(1,1),build(1,n);
	for(int i=1;i<=n-1;i++) slovechange(a[i],a[i+1]);
	slove(1,1,n);
	//for(int i=1;i<=n;i++) printf("%d\n",query(1,pos[i],pos[i]));
	for(int i=1;i<=n;i++) printf("%d\n",s[pos[i]]);
	return 0;
}
