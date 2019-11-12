#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
int n,m,s[MAXN],tot,g[MAXN];
bool jd(int k)
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(sum>=0&&sum<(g[i]-g[i-1])) sum=0;
		else 
		sum-=g[i]-g[i-1];
		sum+=s[i]-k;
	}
	if(sum>=0) return 1;
	else return 0;
}
int erfen()
{
	int mid,l=0,r=1000000001;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(jd(mid)) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i]>>s[i];
	}
	cout<<erfen();
	return 0;
}
