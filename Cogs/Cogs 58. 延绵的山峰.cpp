#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 1000001
#define D 51
using namespace std;
int f[D+5][MAXN],s[D+5][MAXN],a[MAXN],n,kk;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void rmq()
{
	int m=log(n)/log(2);
	for(int i=0;i<=n;i++) f[0][i]=a[i];
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n-(1<<i)+1;j++)
	    f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
}
int querymax(int l,int r){
	int m=int(log(r-l+1.0)/log(2.0));
	return max(f[m][l],f[m][r-(1<<m)+1]);
}
int main()
{
	freopen("climb.in","r",stdin);
	freopen("climb.out","w",stdout);
	int x,y;
	n=read();
	for(int i=0;i<=n;i++)
	  a[i]=read();
	rmq();kk=read();
	for(int i=1;i<=kk;i++)
	  {
	  	x=read();y=read();
	  	printf("%d\n",querymax(x,y));
	  }
	return 0;
}
