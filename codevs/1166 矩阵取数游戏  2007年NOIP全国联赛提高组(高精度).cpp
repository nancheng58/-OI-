#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 81
using namespace std;
int n,m,g[MAXN][MAXN][MAXN],f[MAXN][MAXN][MAXN];
int ans[MAXN],tmp[MAXN],tmp2[MAXN],t[MAXN];
void read(int x,int y)
{
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') g[x][y][++g[x][y][0]]=(ch-48)<<1,ch=getchar();
	for(int i=1;i<=g[x][y][0]/2;i++) swap(g[x][y][i],g[x][y][g[x][y][0]-i+1]);
	for(int i=1;i<=g[x][y][0];i++) 
	if(g[x][y][i]>9) g[x][y][i+1]+=g[x][y][i]/10,g[x][y][i]%=10;
	if(g[x][y][g[x][y][0]+1]) g[x][y][0]++;
	return ;
}
void add(int c[MAXN],int a[MAXN],int p,int b[MAXN],bool flag)
{
	if(!(p&1))
	{
	  for(int i=0;i<=max(a[0],b[0])+1;i++) t[i]=0;t[0]=a[0];
	  for(int i=1;i<=a[0];i++)
	    {
	    	t[i]+=a[i]<<1;
			if(t[i]>9) t[i+1]=t[i]/10,t[i]%=10;
		}
	  if(t[t[0]+1]) t[0]++;
	  c[0]=max(t[0],b[0]);
	  for(int i=1;i<=c[0]+1;i++) c[i]=0;
	  for(int i=1;i<=c[0];i++)
		c[i]=t[i]+b[i];
	  for(int i=1;i<=c[0];i++)
		if(c[i]>9) c[i+1]+=c[i]/10,c[i]%=10;
	  if(c[c[0]+1]) c[0]++;
	}
	else
	{
		c[0]=max(a[0],b[0]);
		if(!flag) for(int i=1;i<=c[0]+1;i++) c[i]=0;
		for(int i=1;i<=c[0];i++)
		  c[i]=a[i]+b[i];
		for(int i=1;i<=c[0];i++)
		  if(c[i]>9) c[i+1]+=c[i]/10,c[i]%=10;
		if(c[c[0]+1]) c[0]++;
	}
	return ;
}
void Max(int c[MAXN],int a[MAXN],int b[MAXN])
{
	if(a[0]>b[0])
	{
		for(int i=0;i<=a[0];i++) c[i]=a[i];
		return ;
	}
	else if(a[0]<b[0])
	{
		for(int i=0;i<=b[0];i++) c[i]=b[i];
		return ;
	}
	for(int i=a[0];i>=1;i--)
	{
		if(a[i]==b[i]) continue;
		if(a[i]>b[i])
		{
			for(int i=0;i<=a[0];i++) c[i]=a[i];
			return ;
		}
		else if(a[i]<b[i])
		{
			for(int i=0;i<=b[0];i++) c[i]=b[i];
			return ;
		}
	}
	for(int i=0;i<=b[0];i++) c[i]=b[i];
	return ;
}
void slove()
{
	for(int k=1;k<=n;k++)
	{
	  for(int i=1;i<=m;i++)
	    add(f[i][i],f[i][i],1,g[k][i],0);
	  for(int i=m;i>=1;i--)
		for(int j=i+1;j<=m;j++)
		{
			add(tmp,f[i][j-1],2,g[k][j],0);
			add(tmp2,f[i+1][j],2,g[k][i],0);
			Max(f[i][j],tmp,tmp2);
		}
	    add(ans,ans,1,f[1][m],1);
		memset(f,0,sizeof f);
	}
	for(int i=ans[0];i;i--) printf("%d",ans[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    read(i,j);
	slove();
	return 0;
}
