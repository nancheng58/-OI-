#include<iostream>
#include<cstdio>
using namespace std;
int n,tot,m,k,sum;
int main()
{
	int x;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		if(i<=k) tot=max(tot,sum);
		if(i>=2)
		sum-=m;
	}
	cout<<tot;
}
