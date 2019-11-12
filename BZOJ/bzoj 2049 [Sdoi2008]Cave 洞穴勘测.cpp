/*
LCT裸题.
然而我并不理解. 
*/
#include<iostream>
#include<cstdio>
#define MAXN 10001
using namespace std;
int n,m,fa[MAXN],tree[MAXN][2],st[MAXN],rev[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
bool isroot(int x)
{
	return tree[fa[x]][0]!=x&&tree[fa[x]][1]!=x;
}
void pushdown(int x)
{
	rev[tree[x][0]]^=1;rev[tree[x][1]]^=1;rev[x]^=1;
	swap(tree[x][0],tree[x][1]);return ;
}
void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	if(tree[y][0]==x) l=0;else l=1;r=l^1;
	if(!isroot(y)){
		if(tree[z][0]==y) tree[z][0]=x;
		else tree[z][1]=x;
	}
	fa[x]=z,fa[y]=x,fa[tree[x][r]]=y;
	tree[y][l]=tree[x][r];tree[x][r]=y;
	return ;
}
void splay(int x)
{
	int top=0,y,z;st[++top]=x;
	for(int i=x;!isroot(i);i=fa[i]) st[++top]=fa[i];
	for(int i=top;i;i--) if(rev[st[i]]) pushdown(st[i]);
	while(!isroot(x))
	{
		y=fa[x],z=fa[y];
		if(!isroot(y))
		{
			if((tree[z][0]==y)^(tree[y][0]==x)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	return ;
}
void access(int x)
{
	int t=0;
	while(x) splay(x),tree[x][1]=t,t=x,x=fa[x];
	return ;
}
void makeroot(int x)
{
	access(x),splay(x),rev[x]^=1;
	return ;
}

void join(int x,int y)
{
	makeroot(x),fa[x]=y,splay(x);
	return ;
}
void cut(int x,int y)
{
	makeroot(x),access(y),splay(y);
	tree[y][0]=fa[x]=0;
	return ;
}
int find(int x)
{
	access(x),splay(x);
	while(tree[x][0]) x=tree[x][0];
	return x;
}
int main()
{
	int x,y;char ch[10];
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",ch);x=read(),y=read();
		if(ch[0]=='C') join(x,y);
		else if(ch[0]=='D') cut(x,y);
		else find(x)==find(y)?printf("Yes\n"):printf("No\n");
	}
	return 0;
}
