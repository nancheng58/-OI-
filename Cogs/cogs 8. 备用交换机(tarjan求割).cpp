#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
int head[MAXN],n,m,tot,cut,ans1,cnt,top,ans,dfn[MAXN],low[MAXN],stack[MAXN];
bool b[MAXN],in[MAXN];
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
	low[u]=dfn[u]=++cnt,stack[++top]=u;in[u]=true;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			if(u==1) ans1++;
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(u!=1&&low[v]>=dfn[u]&&!b[u])
			ans++,b[u]=true;
		}
		else if(in[v]) 
		low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	freopen("gd.in","r",stdin);
	freopen("gd.out","w",stdout);
	int x,y;
	n=read();
	while(scanf("%d%d",&x,&y)!=EOF)
		add(x,y),add(y,x);
	tarjan(1);
	if(ans1>=2) ans++,b[1]=true;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	  if(b[i]) printf("%d\n",i);
	return 0;
}
