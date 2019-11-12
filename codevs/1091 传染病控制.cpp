/*
一开始按照某个根搞.
然后搞着搞着就乱套了.
然后正解是按层做.
随便找一个子节点切断路径然后搜下去.
枚举所有情况.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 301
using namespace std;
struct data{int x[MAXN],l;}s[MAXN];
int n,m,g[MAXN][MAXN],sum,ans=1e9,tot=1,c[MAXN],fa[MAXN];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x*f;
}
int slove(int u,int f)
{
	fa[u]=f;
    for(int i=1;i<=n;i++)
    {
        if(g[u][i]&&!fa[i]&&i!=f) 
        {
			s[u].x[++s[u].l]=i;
            slove(i,u);
        }
    }
}
void dfs(int p)
{
   	bool flag=false;
    if(tot>=ans) return ;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==p)
        {
            for(int j=1;j<=s[i].l;j++)
            {
            	flag=true;
            	c[s[i].x[j]]=p+1;
            	tot++;
            }
        }
    }
    tot--;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==p+1)
        {
        	c[i]=0;
            dfs(p+1);
			c[i]=p+1;
        }
    }
    tot++;
    for(int i=1;i<=n;i++)
      if(c[i]==p+1) c[i]=0,tot--;
    if(!flag) {
    	ans=min(ans,tot);return;
    }
}
int main()
{
    int x,y;
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        x=read(),y=read();
        g[x][y]=true;
        g[y][x]=true;
    }
    slove(1,0);
	c[1]=1;
    dfs(1);
    printf("%d",ans);
    return 0;
}
