/*
主席树维护区间和.
性质:我们现在假设[1,ans]里的数都能被凑出来 
那么ans+1成为神秘数的充要条件是小于ans的数的∑小于ans
(大概是吧) 
*/
#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
int n,m,cut,root[MAXN],a[MAXN],max1,sum,ans;
struct data{int lc,rc,sum;}tree[MAXN*100];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int last,int &k,int l,int r,int p)
{
	k=++cut;tree[k].sum=tree[last].sum+p;
	if(l==r) return;
	tree[k].lc=tree[last].lc,tree[k].rc=tree[last].rc;
	int mid=(l+r)>>1;
	if(p<=mid) add(tree[last].lc,tree[k].lc,l,mid,p);
	else add(tree[last].rc,tree[k].rc,mid+1,r,p);
}
int query(int x,int y,int l,int r,int p)
{
	if(l==r) return tree[y].sum-tree[x].sum;
	int mid=(l+r)>>1;
	if(p<=mid) return query(tree[x].lc,tree[y].lc,l,mid,p);
	else return tree[tree[y].lc].sum-tree[tree[x].lc].sum
				+query(tree[x].rc,tree[y].rc,mid+1,r,p);
}
int main()
{
	int x,y;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),max1=max(max1,a[i]);
	for(int i=1;i<=n;i++) add(root[i-1],root[i],1,max1,a[i]);
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();ans=1;
		while(true)
		{
			sum=query(root[x-1],root[y],1,max1,ans);
			if(ans>sum) break;
			ans=sum+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
