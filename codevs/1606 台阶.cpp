#include<iostream>
#include<cstdio>
#define MAXN 1000000
#define mod 123321
using namespace std;
int f[MAXN];
int main()
{
	int n,m;
	cin>>n>>m;
	f[0]=1;
	if(m!=1)
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(i!=m)
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	cout<<f[n];
	return 0;
}
