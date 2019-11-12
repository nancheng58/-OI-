#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 8010
using namespace std;
struct data
{
	int v;
	int next;
}
e[MAXN];
int tot,top,ans,sum,n,m,b[MAXN],cut,dfn[MAXN],low[MAXN],stack[MAXN],a[MAXN],w[MAXN],head[MAXN],c[MAXN];
bool in[MAXN],flag,s[MAXN];
void add_edge(int u,int v)
{
	e[tot].v=v;
	e[tot].next=head[u];
	head[u]=tot++;
}
void tarjan(int u)
{
	int v;
	in[u]=true;
	low[u]=dfn[u]=++cut;
	stack[top++]=u;
	for(int i=head[u];i!=-1;i=e[i].next)
	{
		v=e[i].v;
		if(!dfn[v])
		  {
		  	tarjan(v);
		  	low[u]=min(low[v],low[u]);
		  }
		else if(in[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u])
	{
		tot++;
		if(!a[tot])a[tot]=11000001;
		do
		{
			v=stack[--top];
			in[v]=0;
			b[v]=tot;
			c[tot]++;
			if(w[v])
			a[tot]=min(a[tot],w[v]);
			//cout<<v<<" ";
		}while(u!=v);
		//cout<<endl;
	}
}
int main()
{
	int x,k,z;
	memset(head,-1,sizeof(head));
	cin>>n;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>z;
		w[x]=z;
	}
	int y;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		add_edge(x,y);
	}
	tot=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		  tarjan(i);
	}
	int out[MAXN]={0};
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=head[i];j!=-1;j=e[j].next)
	  	{
	  		if(b[e[j].v]!=b[i])
	  		  out[e[j].v]++;
		  }
	  }
	  for(int i=1;i<=n;i++)
	  {
	  	if(!out[i]&&c[b[i]]==1)
	  	{
	  		flag=true;
	  		if(w[i])
	  		  sum+=w[i];
	  		else
	  		{
	  			printf("NO\n%d",i);
	  			return 0;
			  }
		  }
	  	/*if(!b[i])
	  	{
	  		printf("NO\n%d",i);
	  		return 0;
		  }*/
	  }
	  /*if(ans>1) 
	  {
	  	cout<<"NO";
		return 0;
	  }*/
	  cout<<"YES"<<endl;
	  if(!flag)
	  {
	  	for(int i=1;i<=n;i++)
	  {
	  	if(!s[b[i]]&&!out[i])
	  	{
	  		s[b[i]]=true;
			  sum+=a[b[i]];
		  }
	  }
	  }
	  cout<<sum;
	return 0;
}
