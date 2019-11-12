#include<iostream>
#include<cstdio>
using namespace std;
int i,j,n,m,k,l;
int a[11];
int main()
{
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>k;
		a[k]++;
	}
	
	for(i=1;i<=10;++i)
	{
		for(j=1;j<=a[i];++j)
		  {
		  	cout<<i;
		  	printf("\n");
		  }
	}
	return 0;
}

