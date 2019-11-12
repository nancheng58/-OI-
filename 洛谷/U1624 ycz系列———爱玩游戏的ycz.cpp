#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct data
{
	int o;
	int r;
	int h;
}
s[100001];
int cmp(const data &x,const data &y)
{
	if(x.r!=y.r)
	return x.r<y.r;
	if(x.h!=y.h)
	return x.h>y.h;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].r>>s[i].h;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].r<<" "<<s[i].h;
		printf("\n");
	}
	return 0;
	  
	  
}
