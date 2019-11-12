#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[2010001];
int main()
{
	int n,m,k;
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
	  {
	  	cin>>a[i];
	  }
	for(int i=m+1;i<=m+n;i++)
	{
		cin>>a[i];
	  }  
	  sort(a+1,a+m+n+1);
	  cout<<a[k];
	  return 0;
}
