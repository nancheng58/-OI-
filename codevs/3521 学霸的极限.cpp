#include<iostream>
#include<cstdio>
using namespace std;
int a[100001];
int main()
{
	int n,m;
	cin>>n;
	a[1]=1;
	a[2]=1;int i=3;
	for(;;i++)
	{
		a[i]=a[i-1]+a[i-2];
		if(a[i]>=n)
		{
			m=i;
			break;
		}
	}
	cout<<m-1<<endl;
	cout<<a[m-1];
	return 0;
}
