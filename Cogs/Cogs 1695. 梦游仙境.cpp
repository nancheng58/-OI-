/*
本蒟蒻做的第一道分块题.
一开始没想到怎么分.
大概就是对于jump值>sqrt(n)的询问暴力处理.
对于jump值<=sqrt(n)的询问做一个预处理.
sum[i][j]表示跳i次,编号(重新编号)为j的点的前缀答案贡献.
查询的时候我们保证了跳跃起点相同的点的编号是连续的
而且查询的[l,r]有贡献的两个端点必定是同一起跳起点跳过来的.
so 前缀和直接相减就可以.
复杂度O(q√n). 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 100001
#define MAXM 320
#define LL long long
using namespace std;
int n,m,K,a[MAXN],s[MAXM][MAXN],g[MAXM][MAXN];
LL sum[MAXM][MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void pre()
{
	int pos;
	for(int i=1;i<=K;i++)//枚举跳的长度. 
	{
	  pos=0;
	  for(int j=1;j<=i;j++)//枚举跳的起点(显然共有i种情况). 
	    for(int k=j;k<=n;k+=i)//跳.
		{
			g[i][k]=++pos;
		  	s[i][pos]=a[k];
		}
	  for(int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+(LL)s[i][j];
	}
}
LL slove1(int l,int r,int jump)
{
	LL tot=0;
	for(int i=l;i<=r;i+=jump) tot+=a[i];
	return tot;
}
LL slove2(int l,int r,int jump)
{
	int ll=l,rr=r-(r-l)%jump;
	if(!jump||ll>=rr) return a[ll];
	ll=g[jump][ll],rr=g[jump][rr];
	return sum[jump][rr]-sum[jump][ll-1];
}
int main()
{
	freopen("XTTMYXJ.in","r",stdin);
	freopen("XTTMYXJ.out","w",stdout);
	int x,y,z;
	n=read(),m=read();K=sqrt(n);
	for(int i=1;i<=n;i++) a[i]=read();
	pre();
	while(m--)
	{
		x=read(),y=read(),z=read();
		if(z>K)  printf("%lld\n",slove1(x,y,z));
		else printf("%lld\n",slove2(x,y,z));
	}
	return 0;
}
