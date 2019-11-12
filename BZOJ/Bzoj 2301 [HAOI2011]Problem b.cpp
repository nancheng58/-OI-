/*
莫比乌斯反演.
好吧这题比上一题简单.
然后容斥的话用二维矩阵想一想就行了.
一开始推式子的时候把推错了一个取值 (打手.
最后是这个东西∑(min(n/k,m/k),d=1)mu[d]*[n/d][m/d]. 
朴素是O(n/k)的,用除法分块优化以后可以降到O(2√n).
用cout输出BZOJ判 Wrong 不知道为啥.
*/
#include<iostream>
#include<cstdio>
#define MAXN 50001
#define LL long long
using namespace std;
int t,a,b,c,d,k,tot,last,mu[MAXN],pri[MAXN];
LL ans,sum[MAXN];
bool vis[MAXN];
void pre()
{
	mu[1]=1;
	for(int i=2;i<=MAXN-1;i++)
	{
		if(!vis[i]) vis[i]=true,pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*pri[j]<=MAXN-1;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]) mu[i*pri[j]]=-mu[i];
			else {mu[i*pri[j]]=0;break;}
		}
	}
	for(int i=1;i<=MAXN-1;i++) sum[i]=sum[i-1]+mu[i];
}
LL slove(LL n,LL m)
{
	ans=0;n/=k,m/=k;
	for(LL i=1;i<=min(n,m);i=last+1)
	{
		last=min(n/(n/i),m/(m/i));
		ans+=(n/i)*(m/i)*(sum[last]-sum[i-1]);
	}
	return ans;
}
int main()
{
	pre();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("%lld\n",slove(b,d)-slove(b,c-1)-slove(a-1,d)+slove(a-1,c-1));
	}
	return 0;
}
