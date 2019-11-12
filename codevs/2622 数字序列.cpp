#include<iostream>
#include<cstdio>
#define MAXN 1001
using namespace std;
int a[MAXN],f[MAXN],tot;
int main()
{
	int n;
	cin>>n;
	cin>>a[1];
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(f[i-1]>0)
		  f[i]=f[i-1]+a[i];
		else f[i]=a[i]; 
		tot=max(f[i],tot);
	}
	cout<<tot;
	return 0;
}
