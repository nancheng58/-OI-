/*
暴力50.
令f[i]表示1到i的最大战斗力.
f[i]=max(f[i],f[j]+
(s[i]-sum[j])*(sum[i]-sum[j])*a+(sum[i]-sum[j])*b+c)
方程显然.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 10001
#define LL long long
using namespace std;
LL f[MAXN],n,sum[MAXN],a,b,c;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove()
{
	memset(f,-127/3,sizeof f);f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		  f[i]=max(f[i],f[j]+
		  (sum[i]-sum[j])*(sum[i]-sum[j])*a+(sum[i]-sum[j])*b+c);
	}
	cout<<f[n];
}
int main()
{
	int x;
	n=read();
	a=read(),b=read(),c=read();
	for(int i=1;i<=n;i++) x=read(),sum[i]=sum[i-1]+x;
	slove();
	return 0;
}

