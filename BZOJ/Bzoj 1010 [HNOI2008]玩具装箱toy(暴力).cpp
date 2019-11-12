/*
DP.
n^2暴力20分。。。
方程显然...
f[i]=min(f[i],f[j-1]+(i-j+sum[i]-sum[j-1]-L)*(i-j+sum[i]-sum[j-1]-L)).
然后开始推斜率的式子... 
*/
#include<iostream>
#include<cstdio>
#define MAXN 50001
#define LL long long
using namespace std;
LL f[MAXN],n,L,sum[MAXN];
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove()
{
	for(int i=1;i<=n;i++) f[i]=1e18;f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		  f[i]=min(f[i],f[j-1]+
		  (i-j+sum[i]-sum[j-1]-L)*(i-j+sum[i]-sum[j-1]-L));
	}
	cout<<f[n];
}
int main()
{
	freopen("bzoj_1010.in","r",stdin);
	freopen("bzoj_1010.out","w",stdout);
	LL x;
	n=read(),L=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		sum[i]=sum[i-1]+x;
	}
	slove();
	return 0;
}
