#include<iostream>
#include<cstdio>
#include<map>
#define MAXN 200001
using namespace std;
int head[MAXN],n,m,tot,cut,ans1,cnt,top,ans,dfn[MAXN],low[MAXN],stack[MAXN];
bool b[MAXN],in[MAXN];
map<int,bool>g[MAXN];
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
	//if(g[u][v]) return;
	//g[u][v]=true;
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
		tot++;int sum=0;
		do{
			v=stack[top--];
			sum++;
			in[v]=false;
			b[v]=true;
		}while(u!=v);
		if(sum==1) b[u]=false;
	}
}
int main()
{
	freopen("messagew.in","r",stdin);
	freopen("messagew.out","w",stdout);
	int x,y;
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	  if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
	  if(b[i]) printf("T\n");
	  else printf("F\n");
	return 0;
}
