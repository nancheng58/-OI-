/*
DP. 
n^2做法.
这题没想出来.
正解要考虑后效性.
因为当我们选择一个任务作为开始的时候
它必然会对后面的决策产生影响.
所以我们先把后效性的贡献算出来累加进去.
方程长这样
f[i]=min(f[i],f[j-1]+(sumw[i]-sumw[j-1])*sumt[i]+S*(sumw[n]-sumw[j-1])) 
sumw表示前缀F[i],sumt表示前缀t[i].
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 5010
using namespace std;
int n,S,F[MAXN],f[MAXN],sumt[MAXN],sumw[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove()
{
	for(int i=1;i<=n;i++) f[i]=1e9;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		  f[i]=min(f[i],f[j-1]+(sumw[i]-sumw[j-1])*sumt[i]+S*(sumw[n]-sumw[j-1]));
	}
	printf("%d",f[n]);
}
int main()
{
	freopen("batch.in","r",stdin);
	freopen("batch.out","w",stdout);
	int x;
	n=read(),S=read();
	for(int i=1;i<=n;i++)
	{
		x=read(),F[i]=read();
		sumt[i]=sumt[i-1]+x;
		sumw[i]=sumw[i-1]+F[i];
	}
	slove();
	return 0;
}

