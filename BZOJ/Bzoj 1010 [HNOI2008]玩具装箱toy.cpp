/*
斜率优化.
乱推一波式子.
就不写了 比较恶心. 
为了方便,令sum[i]=(∑a[i])+i.
所以sum是单调的
上凸点是没有用的.
维护一个下凸性.
第一,二次都没推对,还是弱啊.
*/
#include<iostream>
#include<cstdio>
#define MAXN 50001
#define LL long long
using namespace std;
LL f[MAXN],n,L,sum[MAXN],q[MAXN],c[MAXN];
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
double F(int x)
{
	return double(f[x]+sum[x]*sum[x]);
}
double check(int x,int y)
{
	return double(F(y)-F(x))/double(sum[y]-sum[x]);
}
void slove()
{
	int head=0,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<tail&&check(q[head],q[head+1])<2*(sum[i]-L-1)) head++;
		f[i]=f[q[head]]+(sum[i]-sum[q[head]]-L-1)*(sum[i]-sum[q[head]]-L-1);
		while(head<tail&&check(q[tail-1],q[tail])>check(q[tail],i)) tail--;
		q[++tail]=i;
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
		c[i]=c[i-1]+x;
		sum[i]=c[i]+i;
	}
	slove();
	return 0;
}
