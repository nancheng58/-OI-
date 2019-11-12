/*
st±Ì–¥∑®.
∏¥‘”∂»O(nlogn+m). 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 1000001
#define D 21
using namespace std;
int n,k,a[MAXN],f[MAXN][D+5],s[MAXN][D+5],mi[D+5];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove()
{
	int k=log(n)/log(2)+1;
	for(int j=1;j<=k;j++)
	  for(int i=1;i<=n-mi[j-1];i++)
	    f[i][j]=max(f[i][j-1],f[i+mi[j-1]][j-1]),
		s[i][j]=min(s[i][j-1],s[i+mi[j-1]][j-1]);
	return ;
}
int querymax(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return max(f[l][k],f[r-mi[k]+1][k]);
}
int querymin(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return min(s[l][k],s[r-mi[k]+1][k]);
}
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	int x,y;
	n=read();k=read();mi[0]=1;
	for(int i=1;i<=D;i++) mi[i]=mi[i-1]<<1;
	for(int i=1;i<=n;i++) a[i]=read(),f[i][0]=s[i][0]=a[i];
	slove();
	for(int i=1;i<=n-k+1;i++) printf("%d ",querymin(i,i+k-1));
	printf("\n");
	for(int i=1;i<=n-k+1;i++) printf("%d ",querymax(i,i+k-1));
	return 0;
}
