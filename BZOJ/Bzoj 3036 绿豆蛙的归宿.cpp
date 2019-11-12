/*
期望=概率*贡献.
然后把贡献停留在点上最后累加.
*/
#include<cstdio>
#define MAXN 100001
using namespace std;
int n,m,cut,tot,out[MAXN],head[MAXN];
double s[MAXN],ans[MAXN],finalans;
struct data{int v,next,x;}e[MAXN*2];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f; 
}
void add(int u,int v,int z)
{
	e[++cut].v=v;
	e[cut].x=z;
	e[cut].next=head[u];
	head[u]=cut;
}
void dfs(int u)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;s[v]=s[u]/out[u];
		dfs(v);
		ans[u]+=s[v]*e[i].x;
	}
	return ;
}
int main()
{
	int x,y,z;
	n=read(),m=read();
	while(m--)
	{
		x=read(),y=read(),z=read();
		add(x,y,z),out[x]++;
	}
	s[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++) finalans+=ans[i];
	printf("%.2lf",finalans);
	return 0;
}
