#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 81
#define LL long long
using namespace std;
LL n,m,g[MAXN][MAXN],f[MAXN][MAXN],ans;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove()
{
	for(LL k=1;k<=n;k++)
	{
	  for(int i=1;i<=m;i++) f[i][i]=g[k][i];
	  for(LL i=m;i>=1;i--)
		for(LL j=i+1;j<=m;j++)
	      f[i][j]=max(f[i][j-1]*2+g[k][j],f[i+1][j]*2+g[k][i]);
	    ans+=f[1][m];
		memset(f,0,sizeof f);
	}
	cout<<ans;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    g[i][j]=read(),g[i][j]<<=1;
	slove();
	return 0;
}
