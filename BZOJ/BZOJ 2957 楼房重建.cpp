#include<algorithm>
#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
struct data{int l,r,lc,rc,bj;double ans,sum;}tree[MAXN*4];
struct node{int x,y;}s[MAXN];
int n,m,cut,ans,tot;
double a[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void build(int l,int r)
{
	int k=++cut;
	tree[k].l=l,tree[k].r=r;
	if(l==r) return ;
	int mid=(l+r)>>1;
	tree[k].lc=cut+1;
	build(l,mid);
	tree[k].rc=cut+1;
	build(mid+1,r);
	return ;
}
int slove(int k,int x)
{
	
}
void updata(int k)
{
	tree[k].ans=max(tree[tree[k].lc].ans,tree[tree[k].rc].ans);
	tree[k].sum=tree[tree[k].lc].sum+slove(tree[k].rc,tree[tree[k].lc].ans);
}
void change(int k,int l,int r,int x,double z)
{
	if(x==tree[k].l&&tree[k].r==x) {
		tree[k].ans=z;
		tree[k].sum=1;
		return ;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(l<mid) change(tree[k].lc,l,mid,x,z);
	if(r>mid) change(tree[k].rc,mid+1,r,x,z);
	updata(k);
	return ;
}
int main()
{
	double t;int x,y;
	n=read(),m=read();
	build(1,n);
	for(int i=1;i<=n;i++)
	{
		x=read(),y=read();
		t=(double)y/x;a[++tot]=t;s[i].x=x,s[i].y=y;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		double x=(double)y/x;
		int p=lower_bound(a+1,a+n+1,x)-a;
		change(1,1,n,s[i].x,p);
		printf("%d\n",tree[1].sum);
	}
	return 0;
}
