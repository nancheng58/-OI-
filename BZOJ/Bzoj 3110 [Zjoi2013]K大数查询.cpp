/*
树套树写法.
bzoj过不了.
可能有负数要离散吧.
线段树套线段树.
外层权值线段树,内层区间线段树维护标记.
对权值建一棵权值线段树.
某个点表示权值在某个范围内的数的个数.
然后对每个点建一棵区间线段树.
表示该权值范围在某个区间的数的个数.
然后查找用类似二分的思想.
*/
#include<iostream>
#include<cstdio>
#define MAXN 50001
using namespace std;
struct data{int lc,rc,sum,size,bj;}tree[MAXN*400];
int n,m,root[MAXN],cut;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void push(int k,int l,int r)
{
	if(!tree[k].lc) tree[k].lc=++cut;
	if(!tree[k].rc) tree[k].rc=++cut;
	tree[tree[k].lc].bj+=tree[k].bj;
	tree[tree[k].rc].bj+=tree[k].bj;
	int mid=(l+r)>>1;
	tree[tree[k].lc].sum+=(mid-l+1)*tree[k].bj;
	tree[tree[k].rc].sum+=(r-mid)*tree[k].bj;
	tree[k].bj=0;
	return ;
}
void add(int &k,int l,int r,int x,int y)
{
	if(!k) k=++cut;
	if(x==l&&r==y)
	{
		tree[k].bj++;
		tree[k].sum+=r-l+1;
		return ;
	}
	if(tree[k].bj) push(k,l,r);
	int mid=(l+r)>>1;
	if(y<=mid) add(tree[k].lc,l,mid,x,y);
	else if(x>mid) add(tree[k].rc,mid+1,r,x,y);
	else add(tree[k].lc,l,mid,x,mid),add(tree[k].rc,mid+1,r,mid+1,y);
	tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum;
	return ;
}
void sloveadd(int x,int y,int z)
//先找到它所在权值的位置然后在[x,y]处加入贡献.
{
	int l=1,r=n,k=1,mid;
	while(l!=r)
	{
		mid=(l+r)>>1;
		add(root[k],1,n,x,y);
		if(z<=mid) r=mid,k=k<<1;
		else l=mid+1,k=(k<<1)+1;
	}
	add(root[k],1,n,x,y);
	return ;
}
int query(int k,int l,int r,int x,int y)
{
	if(!k) return 0;
	if(tree[k].bj) push(k,l,r);
	if(x<=l&&r<=y) return tree[k].sum;
	int tot=0,mid=(l+r)>>1;
	if(x<=mid) tot+=query(tree[k].lc,l,mid,x,y);
	if(y>mid) tot+=query(tree[k].rc,mid+1,r,x,y);
	return tot;
}
int slovequery(int x,int y,int z)
{
	int l=1,r=n,k=1;
	while(l!=r)
	{
		int mid=(l+r)>>1;
		int t=query(root[k<<1],1,n,x,y);
		if(t>=z) r=mid,k<<=1;
		else l=mid+1,k=(k<<1)+1,z-=t;
	}
	return l;
}
int main()
{
	freopen("zjoi13_sequence.in","r",stdin);
	freopen("zjoi13_sequence.out","w",stdout);
	int k,x,y,z;
	n=read(),m=read();
	while(m--)
	{
		k=read(),x=read(),y=read(),z=read();
		if(k&1) sloveadd(x,y,n-z+1);
		else printf("%d\n",n-slovequery(x,y,z)+1);
	}
	return 0;
}
