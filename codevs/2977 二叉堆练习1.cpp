#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		if(2*j+1>n) break;
	  	if(a[j]>=a[2*j+1]||a[j]>=a[2*j])
	   {
		cout<<"NO";
		exit(0);
	}
	}
	cout<<"YES";
}
