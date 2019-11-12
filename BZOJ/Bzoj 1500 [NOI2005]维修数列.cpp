#include<iostream>
#include<cstdio>
#define MAXN 4000010
#define INF 1e9
using namespace std;
int n,m,t1,t2,tot,total,size[MAXN],id[MAXN],root,s[MAXN],sum[MAXN],fa[MAXN],tree[MAXN][2],rev[MAXN];
int tag[MAXN],maxl[MAXN],maxr[MAXN],max1[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void push(int k)
{
	if(tag[k]){
		if(tree[k][0]) {
			s[tree[k][0]]+=tag[k],tag[tree[k][0]]+=tag[k];
			sum[tree[k][0]]+=tag[k]*size[tree[k][0]];
		}
	    if(tree[k][1]) {
			s[tree[k][1]]+=tag[k],tag[tree[k][1]]+=tag[k];
			sum[tree[k][1]]+=tag[k]*size[tree[k][1]];
		}
	}
	if(rev[k]){
		rev[tree[k][0]]^=1,rev[tree[k][1]]^=1,rev[k]^=1;
		swap(tree[k][0],tree[k][1]);
	}
	return ;
}
void updata(int k)
{
	size[k]=size[tree[k][0]]+size[tree[k][1]]+1;
	maxl[k]=max(maxl[tree[k][0]],sum[tree[k][0]]+s[k]+maxl[tree[k][1]]);
	maxr[k]=max(maxr[tree[k][1]],sum[tree[k][1]]+s[k]+maxr[tree[k][0]]);
	max1[k]=max(max(max1[tree[k][0]],max1[tree[k][1]]),maxr[tree[k][0]]+maxl[tree[k][1]]);
	sum[k]=sum[tree[k][0]]+sum[tree[k][1]]+s[k];
	return ;
}
void rotate(int x,int &k)
{
	int y=fa[x],z=fa[y],l,r;
	if(tree[y][0]==x) l=0;else l=1;r=l^1;
	if(rev[y]) push(y);
	if(rev[x]) push(x);
	if(y==k) k=x;
	else {
		if(tree[z][0]==y) tree[z][0]=x;
		else tree[z][1]=x;
	}
	updata(y),updata(x);
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
			if((tree[z][0]==y)^(tree[y][0]==x)) rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
	return ;
}
void add(int &k,int f,int x,int y)
{
	if(!k)
	{
		k=++tot;id[tot]=x;s[tot]=y;size[k]=1;fa[k]=f;
		max1[k]=maxl[k]=maxr[k]=y;splay(k,root);return ;
	}
	if(x<=id[k]) add(tree[k][0],k,x,y);
	else add(tree[k][1],k,x,y);
	return ;
}
int query(int x,int k)
{
	if(tag[k]||rev[k]) push(k);
	if(size[tree[k][0]]+1==x) return x;
	if(size[tree[k][0]]>=x) return query(x,tree[k][0]);
	else return query(x-size[tree[k][0]]-1,tree[k][1]);
}
void sloveadd(int x,int y)
{
	int k;
	t1=query(x,root),t2=query(y+2,root);
	splay(t1,root),splay(t2,tree[t1][1]);
	k=read();
	tree[t2][0]=++tot;s[tot]=k,size[tot]++,max1[tot]=maxl[tot]=maxr[tot]=k;
	for(int i=1;i<=total-x-1;i++)
	{
		k=read(),tree[tot-1][1]=++tot;
		s[tot]=k,size[tot]++,max1[tot]=maxl[tot]=maxr[tot]=k;
	}
	splay(tot,root);
	return ;
}
void slovequerysum(int x,int y)
{
	t1=query(x,root),t2=query(y+2,root);
	splay(t1,root),splay(t2,tree[t1][1]);
	printf("%d\n",sum[tree[t2][0]]);
}
void sloverever(int x,int y)
{
	t1=query(x,root),t2=query(y+2,root);
	splay(t1,root),splay(t2,tree[t1][1]);
	rev[tree[t2][0]]^=1;return ;
}
void slovedelete(int x,int y)
{
	t1=query(x,root),t2=query(y+2,root);
	splay(t1,root),splay(t2,tree[t1][1]);
	tree[t2][0]=0;splay(t2,root);return ;
}
void slovechange(int x,int y,int z)
{
	t1=query(x,root),t2=query(y+2,root);
	splay(t1,root),splay(t2,tree[t1][1]);
	int k=tree[t2][0];
	tag[k]=z;s[k]=z;
	sum[k]=z*size[k];
	return ;
}
int main()
{
	int x,y;char ch[13];
	n=read(),m=read();
	add(root,root,0,0),add(root,root,n+2,0);
	for(int i=2;i<=n+1;i++) x=read(),add(root,root,i,x);
	while(m--)
	{
		scanf("%s",ch);
		if(ch[0]=='I') x=read(),total=read(),sloveadd(x,x+1);
		else if(ch[0]=='G') x=read(),total=read(),slovequerysum(x,x+total);
		else if(ch[0]=='D') x=read(),total=read(),slovedelete(x,x+total);
		else if(ch[0]=='R') x=read(),total=read(),sloverever(x,x+total); 
		else if(ch[2]=='K') x=read(),total=read(),y=read(),slovechange(x,x+total,y);
		else printf("%d\n",max1[root]);
	}
	return 0;
}
