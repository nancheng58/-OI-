/*
莫比乌斯反演.
水题.
推一波式子搞搞.
然后就1A了2333.
*/
#include<iostream>
#include<algorithm>
#define LL long long
#define MAXN 100001
using namespace std;
int phi[MAXN],tot,pri[MAXN];
LL ans,n,m,sum[MAXN];
bool vis[MAXN];
void pre()
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) pri[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*pri[j]<=n;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]) phi[i*pri[j]]=phi[i]*(pri[j]-1);
			else
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
		}
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(LL)phi[i];
}
void slove()
{
	int last;
	
	for(int i=1;i<=m;i=last+1)
	{
		last=min(n/(n/i),m/(m/i));
		ans+=(n/i)*(m/i)*(sum[last]-sum[i-1]);
	}
	ans*=2;
	ans-=(LL)m*n;
}
int main()
{
	cin>>n>>m;
	if(n<m) swap(n,m);
	pre();
	slove();
	cout<<ans;
	return 0;
}
