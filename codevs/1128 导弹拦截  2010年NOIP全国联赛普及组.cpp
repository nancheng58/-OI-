#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct data
{
	int n;
	int x;
}
a[100001],b[100001];
int x1,x2,y1,y2,tot,min1=10000001;
int js1(int x,int y)
{
	return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}
int js2(int x,int y)
{
	return (x-x2)*(x-x2)+(y-y2)*(y-y2);
}
int cmp(const data &w,const data &y)
{
	return w.x>y.x;
}
int main()
{
	int n,x,y;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>x>>y;
	  	a[i].n=i;
	  	b[i].n=i;
	  	a[i].x=js1(x,y);
	  	b[i].x=js2(x,y);
	  }
	  a[0].x=0;
	  b[0].x=0;
	  sort(a+1,a+n+1,cmp);
	  for(int i=1;i<=n;i++)
	  {
	  	min1=min(min1,a[i].x+tot);
	  	tot=max(tot,b[a[i].n].x);
	  }
	  cout<<min1;
	  return 0;
}
