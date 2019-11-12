#include<iostream>
#include<cstdio>
#define MAXN 1000001
using namespace std;
bool flag;
long long n,m,f[MAXN],a[MAXN],tot,g[MAXN],w[MAXN];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	f[1]=a[1];
	long long maxx=a[1];
	w[1]=a[1];
	for(int i=2;i<=n;i++)//×î´ó×Ö¶ÎºÍ 
	{
		f[i]=max(f[i-1]+a[i],a[i]);
        w[i]=max(w[i-1],f[i]);
	}
	g[1]=w[1];
	g[2]=w[1]+g[1];
	if(g[2]>=g[1])
	  flag=1;
	for(int i=3;i<=n;i++)
	{
		if(w[i-1]>0)
		{
			g[i]=(w[i-1]+g[i-1])%m;
			if(g[i]>g[1]) flag=1;
		}
		else g[i]=g[2];
	}
	if(flag)
	  cout<<g[n];
	else cout<<g[1]%m; 
	return 0;
}
