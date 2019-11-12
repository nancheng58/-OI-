/*
莫比乌斯函数+容斥原理+二分答案.
这题很明显就是求mu[i]等于0的i的个数.
一个完全平方数必然是素数的乘积们.
用容斥原理小于等于x的完全平方数的个数为
偶数个质数的平方的倍数的个数-奇数个质数的平方的倍数的个数.
容斥系数正好等于mu值.
上界不会超过2*n.
复杂度O(√nlogn).
*/
#include<iostream>
#include<cmath>
#define LL long long
#define MAXN 400001
using namespace std;
int mu[MAXN],tot,pri[MAXN];
LL ans,n;
bool vis[MAXN];
void pre()
{
	mu[1]=1;
	for(int i=2;i<=MAXN-1;i++)
	{
		if(!vis[i]) pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*pri[j]<=MAXN-1;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]) mu[i*pri[j]]=-mu[i];
			else
			{
				mu[i*pri[j]]=0;
				break;
			}
		}
	}
}
bool check(LL x)
{
	LL tot=0;
	int p=sqrt(x);
	for(LL i=1;i<=p;i++) tot+=mu[i]*(x/(i*i));
	return tot>=n;
}
void erfen(LL l,LL r)
{
	ans=0;
	LL mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
}
int main()
{
	int t;pre();
	cin>>t;
	while(t--)
	{
		cin>>n;
		erfen(1,2*n);
		cout<<ans<<endl;
	}
	return 0;
}
