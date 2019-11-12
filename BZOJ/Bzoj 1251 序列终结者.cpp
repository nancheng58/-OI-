/*
splay区间翻转.
还是没太懂原理orz.
搞一个中序遍历树.
学了学建树姿势2333. 
注意下放的时候先看有没有左右子树.
*/
#include<iostream>
#include<cstdio>
#define MAXN 50010
#define INF 1e9
using namespace std;
int n,m,t1,t2,size[MAXN],fa[MAXN],s[MAXN],tag[MAXN],tree[MAXN][2],tot,cut,root,max1[MAXN],id[MAXN];
bool rev[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void updata(int k)
{
	size[k]=size[tree[k][0]]+size[tree[k][1]]+1;
	max1[k]=max(max(max1[tree[k][0]],max1[tree[k][1]]),s[k]);
	return ;
}
void push(int k)
{
	if(tag[k]){//1 W.
		if(tree[k][0]) tag[tree[k][0]]+=tag[k],s[tree[k][0]]+=tag[k],max1[tree[k][0]]+=tag[k];
		if(tree[k][1]) tag[tree[k][1]]+=tag[k],s[tree[k][1]]+=tag[k],max1[tree[k][1]]+=tag[k];
		tag[k]=0;
	}
	if(rev[k]){
		rev[tree[k][0]]^=1;rev[tree[k][1]]^=1;
		swap(tree[k][0],tree[k][1]);
		swap(id[tree[k][0]],id[tree[k][1]]);
		rev[k]^=1;
	}
	return ;
}
void build(int l,int r,int f)
{
	if(l>r) return ;
	int mid=(l+r)>>1,k=id[mid],last=id[f];
	if(l==r)
	{
		size[l]=1;fa[l]=last;
		if(l<f) tree[last][0]=k;
		else tree[last][1]=k;
	}
	build(l,mid-1,mid),build(mid+1,r,mid);
	fa[k]=last;updata(k);
	if(k<last) tree[last][0]=k;
	else tree[last][1]=k;
	return ;
}
void rotate(int x,int &k)
{
	int y=fa[x],z=fa[y],l,r;
	if(tree[y][0]==x) l=0;else l=1;r=l^1;
	if(y==k) k=x;
	else {
		if(tree[z][0]==y) tree[z][0]=x;
		else tree[z][1]=x;
	}
	fa[y]=x,fa[x]=z;fa[tree[x][r]]=y;
	tree[y][l]=tree[x][r],tree[x][r]=y;
	updata(y),updata(x);return ;
}
void splay(int x,int &k)
{
	int y,z;
	while(x!=k)
	{
		y=fa[x],z=fa[y];
		if(y!=k)
		{
			if((tree[z][0]==y)^(tree[y][0]==x)) rotate(x,k);
			rotate(y,k);
		}
		rotate(x,k);
	}
	return ;
}
int query(int k,int x)
{
	if(tag[k]||rev[k]) push(k);
	if(size[tree[k][0]]+1==x) return k;
	if(size[tree[k][0]]>=x) return query(tree[k][0],x);
	else return query(tree[k][1],x-size[tree[k][0]]-1);
}
void slovechange(int x,int y,int z)
{
	t1=query(root,x);
	t2=query(root,y+2);
	splay(t1,root),splay(t2,tree[t1][1]);
	tag[tree[t2][0]]+=z;s[tree[t2][0]]+=z;max1[tree[t2][0]]+=z;
	return ;
}
int querymax(int x,int y)
{
	t1=query(root,x);
	t2=query(root,y+2);
	splay(t1,root),splay(t2,tree[t1][1]);
	return max1[tree[t2][0]];
}
void rever(int x,int y)
{
	t1=query(root,x);
	t2=query(root,y+2);
	splay(t1,root),splay(t2,tree[t1][1]);
	rev[tree[t2][0]]^=1;
	return ;
}
int main()
{
	int x,y,z,k;
	n=read(),m=read();
	max1[0]=-INF;
	for(int i=1;i<=n+2;i++) id[i]=i;
	build(1,n+2,0),root=(n+3)>>1;
	while(m--)
	{
		k=read();
		if(k==1) x=read(),y=read(),z=read(),slovechange(x,y,z);
		else if(k==2) x=read(),y=read(),rever(x,y);
		else x=read(),y=read(),printf("%d\n",querymax(x,y));
	}
	return 0;
}
