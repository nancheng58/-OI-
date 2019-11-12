#include<iostream>
#include<cstdio>
#define MAXN 100001 
using namespace std;
bool b[MAXN];
int tot,sum;
int main()
{
	int n,m,x,l,r;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	  b[i]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		  b[j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]) tot++;
		else tot=0;
		if(tot==x) tot=0,sum++;
	}
	cout<<sum;
	return 0;
}
