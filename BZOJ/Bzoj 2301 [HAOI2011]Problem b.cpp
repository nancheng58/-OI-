/*
Ī����˹����.
�ð��������һ���.
Ȼ���ݳ�Ļ��ö�ά������һ�������.
һ��ʼ��ʽ�ӵ�ʱ����ƴ���һ��ȡֵ (����.
��������������(min(n/k,m/k),d=1)mu[d]*[n/d][m/d]. 
������O(n/k)��,�ó����ֿ��Ż��Ժ���Խ���O(2��n).
��cout���BZOJ�� Wrong ��֪��Ϊɶ.
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
