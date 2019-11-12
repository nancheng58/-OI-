#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
int a[MAXN],f[MAXN],n,tot=-1*MAXN;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(f[i-1]>0)
		  f[i]=f[i-1]+a[i];
		else f[i]=a[i];  
		tot=max(tot,f[i]);
	}
	cout<<tot;
	return 0;
}
