/*
莫比乌斯反演.
算是模板题了吧.... 
*/
#include<iostream>
#include<cstdio>
#define LL long long
#define MAXN 10000010
using namespace std;
int pri[MAXN],tot,mu[MAXN];
LL n,g[MAXN],sum[MAXN],ans;
bool vis[MAXN];
void pre()
{
	mu[1]=1;
	for(int i=2;i<=n;i++)
	  {
	  	if(!vis[i]) pri[++tot]=i,mu[i]=-1,g[i]=1;
	  	for(int j=1;j<=tot&&i*pri[j]<=n;j++)
	  	{
	  		vis[i*pri[j]]=true;
	  		if(i%pri[j])
	  		{
	  			mu[i*pri[j]]=-mu[i];
	  			g[i*pri[j]]=-g[i]+mu[i];
			}
			else
			{
				mu[i*pri[j]]=0;
				g[i*pri[j]]=mu[i];
				break;
			}
		}
	  }
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+g[i];
}
int main()
{
	LL last;
	cin>>n;
	pre();
	for(LL i=1;i<=n;i=last+1)
	{
		last=n/(n/i);
		ans+=(LL)(n/i)*(n/i)*(sum[last]-sum[i-1]);
	}
	printf("%lld",ans);
	return 0;
}
