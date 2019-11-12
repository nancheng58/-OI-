#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200001
using namespace std;
int head[MAXN],n,m,tot,cut,ans1,cnt,out[MAXN],be[MAXN],top,ans,dfn[MAXN],low[MAXN],b[MAXN],stack[MAXN],sum;
bool in[MAXN];
struct data{int v,next;}e[MAXN*2];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x*f;
}
void add(int u,int v)
{
	e[++cut].v=v;
	e[cut].next=head[u];
	head[u]=cut;
}
void tarjan(int u)
{
	int v;
	low[u]=dfn[u]=++cnt,stack[++top]=u;in[u]=true;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		tot++;
		do{
			v=stack[top--];
			be[v]=tot;
			in[v]=false;
		}while(u!=v);
	}
}
void slove()
{
	tot=cut=cnt=sum=top=0;
	memset(head,0,sizeof head);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(be,0,sizeof be);
	memset(out,0,sizeof(out));
}
int main()
{
	freopen("buss.in","r",stdin);
	freopen("buss.out","w",stdout);
	int x,y;
	while(true)
	{
		n=read();
		slove();
		if(!n) break;
		m=read();
		for(int i=1;i<=m;i++)
		{
			x=read(),y=read();
			add(x,y);
		}
		for(int i=1;i<=n;i++)
	  	  if(!dfn[i]) tarjan(i);
	  	for(int i=1;i<=n;i++)
	  	  for(int j=head[i];j;j=e[j].next)
	  	  	  if(be[i]!=be[e[j].v]) out[be[i]]++;
		for(int i=1;i<=n;i++)
		  if(!out[be[i]]) b[++sum]=i;
		sort(b+1,b+sum+1);
		for(int i=1;i<=sum;i++)
	  	  printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
