#include<iostream>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	int n,x,y,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=x;j<=y;j++)
		{
			a[j]++;
		}
	}
	int k;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		cout<<a[k];
		printf("\n");
	}
	return 0;
}
