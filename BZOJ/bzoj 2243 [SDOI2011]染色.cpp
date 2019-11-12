/*
树链剖分+线段树.
读入操作的时候要用ch[2] scanf 读入(又被卡了).
这还是shenben告诉我的%%%.
以为用树剖搞贡献可能无法处理衔接点.
然后就yy了一种类似于暴力的做法.
倍增处理出lca然后跳链.
一开始只能得70分不知道为啥(写的很鬼畜~).
原来是没写lca是链顶的情况.
网上大多数人的做法是处理区间贡献
然后单点查询判断端点情况,
一开始因为想到找链的时候两个点蹦跶可能不好处理端点
然后就没这样搞...
其实我们可以先处理出段点的贡献(还是有点晕~). 
通过这题还会了手动开栈.
我是找的lca然后分情况讨论乱搞.
这题线段树merge什么的都还好.
还有几个需要注意的地方:
build tree 标号,update &&pushtag.
最重要的是读入读入读入！！！
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100001
using namespace std;
struct data{int l,r,lc,rc,sum,lans,rans,bj;}tree[MAXN<<2];
struct edge{int v,next;}e[MAXN*2];
int n,m,cut,head[MAXN],a[MAXN];
int maxsize,size[MAXN],pos[MAXN],top[MAXN],deep[MAXN],fa[MAXN][25];
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
void update(int k)
{
	if(tree[tree[k].lc].rans==tree[tree[k].rc].lans)
		tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum-1;
	else tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum;
	tree[k].lans=tree[tree[k].lc].lans;tree[k].rans=tree[tree[k].rc].rans;
	return ;
}
void push(int k)
{
	tree[tree[k].lc].bj=tree[tree[k].rc].bj=tree[k].bj;
	tree[tree[k].lc].lans=tree[tree[k].lc].rans=tree[k].bj;
	tree[tree[k].rc].lans=tree[tree[k].rc].rans=tree[k].bj;
	tree[tree[k].lc].sum=tree[tree[k].rc].sum=1;
	tree[k].bj=0;
	return ;
}
void build(int l,int r)
{
	int k=++cut;tree[k].l=l,tree[k].r=r;
	if(l==r) return ;// 1w.
	int mid=(l+r)>>1;
	tree[k].lc=cut+1;build(l,mid);
	tree[k].rc=cut+1;build(mid+1,r);
	update(k);return ;
}
void change(int k,int l,int r,int z)
{
	if(l<=tree[k].l&&tree[k].r<=r) {
		tree[k].sum=1;
		tree[k].lans=tree[k].rans=z;
		tree[k].bj=z;
		return ;
	}
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(l<=mid) change(tree[k].lc,l,r,z);
	if(r>mid) change(tree[k].rc,l,r,z);
	update(k);//２w.
	return ;
}
data query(int k,int l,int r)
{
	data xx;
	if(l<=tree[k].l&&tree[k].r<=r) return tree[k];
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(l>mid) return query(tree[k].rc,l,r);
	else if(r<=mid) return query(tree[k].lc,l,r);
	else
	{
		data ll=query(tree[k].lc,l,mid);
		data rr=query(tree[k].rc,mid+1,r);
		if(ll.rans==rr.lans) xx.sum=ll.sum+rr.sum-1;
		else xx.sum=ll.sum+rr.sum;
		xx.lans=ll.lans,xx.rans=rr.rans;
	}
	update(k);
	return xx;
}
void dfs1(int u)
{
	size[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!fa[v][0]) fa[v][0]=u,deep[v]=deep[u]+1,dfs1(v),size[u]+=size[v];
	}
	return ;
}
void dfs2(int u,int top1)
{
	pos[u]=++maxsize;top[u]=top1;
	int k=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(fa[v][0]==u&&size[v]>size[k]) k=v;
	}
	if(!k) return ;
	dfs2(k,top1);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(fa[v][0]==u&&v!=k) dfs2(v,v);
	}
	return ;
}
void slovechange(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		change(1,pos[top[x]],pos[x],z);
		x=fa[top[x]][0];
	}
	if(pos[x]>pos[y]) swap(x,y);
	change(1,pos[x],pos[y],z);
	return ;
}
int get_same(int u,int v)
{
	for(int i=0;i<=20;i++)
	  if(v&(1<<i)) u=fa[u][i];
	return u;
}
int lca(int u,int v)
{
	if(deep[u]<deep[v]) swap(u,v);
	u=get_same(u,deep[u]-deep[v]);
	if(u==v) return u;
	for(int i=20;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i])
		  u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
int get(int k,int x)
{
	if(tree[k].l==tree[k].r) return tree[k].lans;
	if(tree[k].bj) push(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid) return get(tree[k].lc,x);
	else return get(tree[k].rc,x);
	update(k);
}
int slovequery(int x,int y)
{
	/*int ans=0;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		ans+=query(1,pos[top[x]],pos[x]).sum;
		if(get(1,pos[top[x]])==get(1,pos[fa[top[x]][0]])) ans--;
		x=fa[top[x]][0];
	}
	if(pos[x]>pos[y]) swap(x,y);
	ans+=query(1,pos[x],pos[y]).sum;
	return ans;*/
	data ans,ansl,ansr;
	int lc=lca(x,y);
	if(top[x]==top[y])
	{
		if(pos[x]>pos[y]) swap(x,y);
		ans=query(1,pos[x],pos[y]);
		return ans.sum;
	}
	if(deep[lc]>deep[top[x]]||lc==top[x]) ansl=query(1,pos[lc],pos[x]);
	else 
	{
		ansl=query(1,pos[top[x]],pos[x]);x=fa[top[x]][0];
		while(deep[lc]<deep[top[x]]) 
		{
			ans=query(1,pos[top[x]],pos[x]);
			if(ans.rans==ansl.lans) ans.sum+=ansl.sum-1;
			else ans.sum+=ansl.sum;
			ans.rans=ansl.rans;
			ansl=ans;
			x=fa[top[x]][0];
		}
		ans=query(1,min(pos[lc],pos[x]),max(pos[lc],pos[x]));
		if(ans.rans==ansl.lans) ans.sum+=ansl.sum-1;
		else ans.sum+=ansl.sum;
		ans.rans=ansl.rans;
		ansl=ans;
	}
	if(deep[lc]>deep[top[y]]||lc==top[y]) ansr=query(1,pos[lc],pos[y]);
	else
	{
		ansr=query(1,pos[top[y]],pos[y]);y=fa[top[y]][0];
		while(deep[lc]<deep[top[y]])
		{
			ans=query(1,pos[top[y]],pos[y]);
			if(ans.rans==ansr.lans) ans.sum+=ansr.sum-1;
			else ans.sum+=ansr.sum;
			ans.rans=ansr.rans;
			ansr=ans;
			y=fa[top[y]][0];
		}
		ans=query(1,min(pos[y],pos[lc]),max(pos[lc],pos[y]));
		if(ans.rans==ansr.lans) ans.sum+=ansr.sum-1;
		else ans.sum+=ansr.sum;
		ans.rans=ansr.rans;
		ansr=ans;
	}
	if(ansl.lans==ansr.lans) ans.sum=ansl.sum+ansr.sum-1;
	else ans.sum=ansl.sum+ansr.sum;
	return ans.sum;
}
void get_father()
{
	for(int j=1;j<=20;j++)
	  for(int i=1;i<=n;i++)
	    fa[i][j]=fa[fa[i][j-1]][j-1];
	return ;
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	/*int ss=64<<20;
	char *p=(char *)malloc(ss)+ss;
	__asm__("movl %0, %%esp\n"::"r"(p));*/
	int x,y,z;char ch[2];
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	fa[1][0]=1;dfs1(1),dfs2(1,1);
	cut=0;build(1,n);
	for(int i=1;i<=n;i++) change(1,pos[i],pos[i],a[i]);
	get_father();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",ch);// n T.... 
		if(ch[0]=='Q') x=read(),y=read(),printf("%d\n",slovequery(x,y));
		else {
			x=read(),y=read(),z=read();
			slovechange(x,y,z);
		}
	}
	return 0;
}
