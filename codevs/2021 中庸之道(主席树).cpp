#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100001
using namespace std;
struct data{int l,r,sum,lc,rc;}tree[MAXN*4];
int n,m,root[MAXN],a[MAXN],s[MAXN],tot,cut,x,y;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
int build(int sum,int l,int r)
{
	int k=++cut;tree[k].sum=sum,tree[k].lc=l,tree[k].rc=r;
	return k;
}
void add(int &now,int last,int l,int r,int p)
{
	now=build(tree[last].sum+1,tree[last].lc,tree[last].rc);
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(p<=mid) add(tree[now].lc,tree[last].lc,l,mid,p);
	else add(tree[now].rc,tree[last].rc,mid+1,r,p);
}
int query(int L,int R,int p,int l,int r)
{
	if(l==r) return r;
	int ans=tree[tree[R].lc].sum-tree[tree[L].lc].sum;
	int mid=(l+r)>>1;
	if(ans>=p) return query(tree[L].lc,tree[R].lc,p,l,mid);
	else return query(tree[L].rc,tree[R].rc,p-ans,mid+1,r);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=a[i];
	sort(s+1,s+n+1);
	tot=unique(s+1,s+n+1)-s-1;
	for(int i=1;i<=n;i++)
	{
		int p=lower_bound(s+1,s+tot+1,a[i])-s;
		add(root[i],root[i-1],1,tot,p);
	}
	int k; 
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();k=((x+y)>>1)-x+1;
		int p=query(root[x-1],root[y],k,1,tot);
		printf("%d\n",s[p]);
	}
	return 0;
}
