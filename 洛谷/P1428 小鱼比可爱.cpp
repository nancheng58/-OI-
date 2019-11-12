#include<iostream>
using namespace std;
int main()
{
	int n,a[101],t[101]={0},i;
	a[0]=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[i]) t[i]++; 
		} 
		 
	}
	for(i=1;i<=n;i++)
	  cout<<t[i]<<" ";
	  return 0;
}
