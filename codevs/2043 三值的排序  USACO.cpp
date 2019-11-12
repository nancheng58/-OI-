#include<iostream>
#include<cstdio>
using namespace std;
int a[101],tot;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n-1;i++)
	  for(int j=1;j=n-i;j++)
	  {
	  	if(a[j]>a[j+1])
	  	{
	  		swap(a[j],a[j+1]);tot++;
		  }
	  }
	cout<<tot;
	return 0;  
}
