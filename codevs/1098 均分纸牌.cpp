#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[10000];
	int n,temp=0,sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	x=sum/n;
	for(int j=1;j<=n;j++)
	{
		if(a[j]<x)
		{
			a[j+1]-=(x-a[j]);
			temp++;
		}
		if(a[j]>x)
		{
			a[j+1]-=(x-a[j]);
			temp++;
		}
	}
	cout<<temp;
	return 0;
}
