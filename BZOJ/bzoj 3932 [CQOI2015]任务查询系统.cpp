/*
离散化+主席树.
这题需要维护两个东西.
第k个优先级是谁&&优先级的价值和.
对于每个优先级建一棵权值线段树.
对于每个时间单独维护更新线段树.
把每个任务拆成两个时间.
做一个差分.
对于没有出现过的时间就直接复制之前的 
(这一点没想到然后看的题解orzorzorz).
按时间排序将每个点插入更新.
这题较坑的地方是query的时候
要返回tree[k].sum/tree[k].size*x.
因为我们只能查到第k个是谁.
但是里边有很多任务吖.
里边的优先级数都是一样的.
我们只能选择里边的k`个.
*/
#include<algorithm>
#include<iostream>
#include<cstdio>
#define LL long long
#define MAXN 100001
using namespace std;
int root[MAXN],n,m,cut,a[MAXN],tot;
LL ans=1;
struct node{int x,p,tag;}s[MAXN*2];
struct data{int lc,rc,size;LL sum;}tree[MAXN*40];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
bool cmp(const node &x,const node &y)
{
	return x.x<y.x;
}
int build(int l,int r)
{
	int k=++tot;
	if(l==r) return k;
	int mid=(l+r)>>1;
	tree[k].lc=build(l,mid);
	tree[k].rc=build(mid+1,r);
	return k;
}
void change(int &now,int last,int l,int r,int x,int tag)
{
	now=++tot;
	tree[now].lc=tree[last].lc,tree[now].rc=tree[last].rc;
	tree[now].sum=tree[last].sum+(LL)tag*a[x];
	tree[now].size=tree[last].size+tag;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(x<=mid) change(tree[now].lc,tree[now].lc,l,mid,x,tag); 
	else change(tree[now].rc,tree[now].rc,mid+1,r,x,tag);
	return ;
}
LL query(int k,int l,int r,int x)
{
	if(l==r) return tree[k].sum/tree[k].size*(LL)x;
	int p=tree[tree[k].lc].size;
	int mid=(l+r)>>1;
	if(p>=x) return query(tree[k].lc,l,mid,x);
	else return tree[tree[k].lc].sum+query(tree[k].rc,mid+1,r,x-p);
}
int main()
{
	freopen("cqoi15_query.in","r",stdin);
	freopen("cqoi15_query.out","w",stdout);
	int t,x,y,z;
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		x=read(),y=read(),z=read();
		s[++cut].x=x,s[cut].p=z,s[cut].tag=1;
		s[++cut].x=y+1,s[cut].p=z,s[cut].tag=-1;
		a[i]=z;
	}
	sort(a+1,a+n+1);
	sort(s+1,s+cut+1,cmp);
	root[0]=build(1,m);
	int j=1;
	for(int i=1;i<=m;i++)
	{
		root[i]=root[i-1];
		while(j<=cut&&s[j].x==i)
		{
			int p=lower_bound(a+1,a+n+1,s[j].p)-a;
			change(root[i],root[i],1,m,p,s[j].tag);
			j++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		t=read();x=read(),y=read(),z=read();
		LL k=1+((LL)x*ans+(LL)y)%z;
		if(k>=tree[root[t]].size) ans=tree[root[t]].sum;
		else ans=query(root[t],1,m,k);
		printf("%lld\n",ans);
	}
	return 0;
}
