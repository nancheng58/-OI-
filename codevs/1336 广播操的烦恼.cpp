#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100001],tot;
int main()
{
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	tot=0;
	  	cin>>k;
	  	for(int j=1;j<=k;j++)
	  	{
	  		cin>>a[j];
		  }
		 sort(a+1,a+k+1);
		 int x=a[(k+1)/2];
		 for(int j=1;j<=k;j++)
		 {
		 	tot+=abs(a[j]-x);
		 }
		 cout<<x<<" "<<tot;
		 printf("\n");
	  }
} 
