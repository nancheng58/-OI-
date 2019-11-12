/*
积性函数.
   n   m
求∑  ∑lcm(i,j).
  i=1 j=1
推一波式子.
ans=∑(s[n/i]*s[m/i]*f[i]).
s[i]=(i*(i+1)/2).
f[i]=i*∑u(d)*d.
     d|i 
然后主要问题就是怎么求f[i]了.
这个东西是积性函数.
筛一下就好了.
复杂度O(n).
算答案的时候不用除法分块可能过不了?
也许是我写的常数比较大吧...
*/
#include<iostream>
#include<cstdio>
#define LL long long
#define MAXN 10000010
#define mod 20101009
#define ni 10050505
using namespace std;
int pri[MAXN],tot,sum[MAXN];
LL n,m,ans,f[MAXN],s[MAXN];
bool vis[MAXN];
void pre()
{
	f[1]=1;
	for(int i=2;i<=n;i++)
	  {
	  	if(!vis[i]) pri[++tot]=i,f[i]=1-i;
	  	for(int j=1;j<=tot&&i*pri[j]<=n;j++)
	  	{
	  		vis[i*pri[j]]=true;
	  		if(i%pri[j]) f[i*pri[j]]=(f[i]*f[pri[j]])%mod;
			else
			{
				f[i*pri[j]]=f[i];
				break;
			}
		}
	  }
	for(LL i=1;i<=n;i++) sum[i]=(sum[i-1]+f[i]*i)%mod;
}
void slove()
{
	int last;
	for(LL i=1;i<=n;i++) s[i]=((i*(i+1))%mod*ni)%mod;
	for(LL i=1;i<=m;i=last+1)
	{
		last=min(n/(n/i),m/(m/i));
		ans=(ans+(s[n/i]%mod*s[m/i]%mod*(LL)(sum[last]-sum[i-1]))%mod+mod)%mod;
	}
	cout<<ans;
}
int main()
{
	cin>>n>>m;
	if(n<m) swap(n,m);
	pre();slove();
	return 0;
}
