#include<iostream>
#include<cstdio>
using namespace std;
int a[201001],b[201001],c[201001];
int tot,n,p,m,x,y,flag;
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(y<=p)
		 flag=i;
		if(flag>=c[x])
		  b[x]=a[x];
		tot+=b[x];
		a[x]++;
		c[x]=i; 
	}
	cout<<tot;
	return 0;
}
