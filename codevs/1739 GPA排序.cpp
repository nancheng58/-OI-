#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
float a[100001];
int main()
{
	int n,m;
	float x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i]=x/y;
	}
	sort(a+1,a+n+1);
	printf("%.2f",a[n-m+1]);
	return 0;
}

