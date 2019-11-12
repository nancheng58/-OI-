/*
splay旋转,查找前驱和后继.
数据可能有负数.
cogs上卡读入优化orz.
*/
#include<iostream>
#include<cstdio>
#define MAXN 50001
#define INF 1e9
using namespace std;
int n,tree[MAXN][2],t1,t2,root,fa[MAXN],num[MAXN],size,ans,x1,x2;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void rotate(int x,int &k)
{
	int y=fa[x],z=fa[y],l,r;
	if(tree[y][0]==x) l=0;else l=1;r=l^1;
	if(y==k) k=x;
	else {
		if(tree[z][0]==y) tree[z][0]=x;//拆. 
		else tree[z][1]=x;
	}
	fa[x]=z,fa[y]=x;fa[tree[x][r]]=y;
	tree[y][l]=tree[x][r];tree[x][r]=y;
	return ;
}
void splay(int x,int &k)
{
	int y,z;
	while(x!=k)
	{
		y=fa[x],z=fa[y];
		if(y!=k)
		{
			if((tree[y][0]==x)^(tree[z][0]==y)) rotate(x,k);//共线旋转孙子. 
			else rotate(y,k);//不共线旋转儿子. 
		}
		rotate(x,k);
	}
	return ;
}
void add(int &k,int x,int f)//加入元素. 
{
	if(!k){size++;k=size;num[k]=x;fa[k]=f;splay(k,root);return;}
	if(x<num[k]) add(tree[k][0],x,k);//维护二叉树性质.
	else add(tree[k][1],x,k);
	return ;
}
void before(int k,int x)//查找前驱.
{
	if(!k) return ;
	if(num[k]<=x){t1=num[k];x1=k;before(tree[k][1],x);}
	else before(tree[k][0],x);
	return ;
}
void after(int k,int x)//查找后继.
{
	if(!k) return ;
	if(num[k]>=x){t2=num[k];x2=k;after(tree[k][0],x);}
	else after(tree[k][1],x);
	return ;
}
int main()
{
	freopen("turnover.in","r",stdin);
	freopen("turnover.out","w",stdout); 
	int x;
	n=read();
	x=read(),add(root,x,0),ans=x;
	for(int i=2;i<=n;i++)
	{
		x=read();//scanf("%d",&x);
		x1=x2=0;
		before(root,x);
		after(root,x);
		if(!x1) ans+=t2-x;
		else if(!x2) ans+=x-t1;
		else ans+=min(x-t1,t2-x);
		add(root,x,0);
	}
	printf("%d",ans);
	return 0;
}
