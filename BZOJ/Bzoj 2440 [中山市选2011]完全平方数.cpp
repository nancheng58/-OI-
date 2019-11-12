/*
Ī����˹����+�ݳ�ԭ��+���ִ�.
��������Ծ�����mu[i]����0��i�ĸ���.
һ����ȫƽ������Ȼ�������ĳ˻���.
���ݳ�ԭ��С�ڵ���x����ȫƽ�����ĸ���Ϊ
ż����������ƽ���ı����ĸ���-������������ƽ���ı����ĸ���.
�ݳ�ϵ�����õ���muֵ.
�Ͻ粻�ᳬ��2*n.
���Ӷ�O(��nlogn).
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
