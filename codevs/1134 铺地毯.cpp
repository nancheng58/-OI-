#include<cstdio>
#include<iostream>
using namespace std;
int w[100010],t[100001],c[100001],d[100001];
int main()
{
	int n,a,b,x,y,g,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>g>>k;
		{
			w[i]=a;t[i]=b;
			c[i]=a+g;d[i]=b+k;
		}
	}
	cin>>x>>y;
	for(int i=n;i>=1;i--)
	{
		if(x>=w[i]&&x<=c[i]&&y>=t[i]&&y<=d[i])
		  {
		  	cout<<i;
		  	return 0;
		  }
	}
	cout<<-1;
	return 0;  
}
