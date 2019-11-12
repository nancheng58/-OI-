/*
背包DP 
c[i][j]表示a[i]这个课题被选择j次时对答案的贡献.
然后分组背包  f[V]表示在V体积时的贡献.
转移的时候只考虑V-j时的答案贡献.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1001
long long m,n,f[MAXN],a[MAXN],b[MAXN],c[MAXN][MAXN];
using namespace std;
long long  init(long long x,long long t)
{
	long long s=1;
	for(int i=1;i<=t;i++) 
		s*=x;
	return s;
}
int main()
{
	memset(f,127/3,sizeof(f));
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			c[i][j]=a[i]*init(j,b[i]);
		}
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int v=m;v>=0;v--)
			for(int j=1;j<=v;j++)
			{
				f[v]=min(f[v],f[v-j]+c[i][j]);
			}
	cout<<f[m];
	return 0;
}


