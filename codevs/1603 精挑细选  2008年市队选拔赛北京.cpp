#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct dat
{
	int l;
	int d;
	int rq;
}
da[1001];
int cmp(const dat &x,const dat &y)
{
	if(x.l!=y.l)
	return x.l>y.l;
	if(x.d!=y.d)
	return x.d<y.d;
	if(x.rq!=y.rq)
	return x.rq>y.rq;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>da[i].l>>da[i].d>>da[i].rq;
	}
	sort(da+1,da+n+1,cmp);
	cout<<da[1].rq;
	return 0;
}
