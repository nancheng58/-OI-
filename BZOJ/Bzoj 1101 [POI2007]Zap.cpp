/*
莫比乌斯反演.
随便搞一搞就好了。。。
用long long 会T 
用cout 会 R  
不知道为啥.
*/
#include<iostream>
#include<cstdio>
#define MAXN 50001
int ans,sum[MAXN],last;
int mu[MAXN],tot,pri[MAXN];
bool vis[MAXN];
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void pre()
{
	mu[1]=1;
	for(int i=2;i<=MAXN-1;i++)
	{
		if(!vis[i]) vis[i]=true,pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*pri[j]<=MAXN-1;j++)
		{
			if(!vis[i*pri[j]]) vis[i*pri[j]]=true;
			if(i%pri[j]) mu[i*pri[j]]=-mu[i];
			else {mu[i*pri[j]]=0;break ;}
		}
	}
	for(int i=1;i<=MAXN-1;i++) sum[i]=sum[i-1]+mu[i];
	return ;
}
void slove(int n,int m,int k)
{
	ans=0;n/=k,m/=k;
	for(int i=1;i<=min(n,m);i=last+1)
	{
		last=min(n/(n/i),m/(m/i));
		ans+=(n/i)*(m/i)*(sum[last]-sum[i-1]);
	}
	printf("%d\n",ans);
	return ;
}
int main()
{
	int t,n,m,k;
	pre();t=read();
	while(t--)
	{
		n=read(),m=read(),k=read();
		slove(n,m,k);
	}
	return 0;
}
