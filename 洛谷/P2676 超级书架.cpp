#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 20001
using namespace std;
int a[MAXN],n,m,tot;
int cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int i=1;
	for(;;i++)
	{
		tot+=a[i];
		if(tot>=m)
		 break;
	}
	cout<<i;
	return 0;
}
