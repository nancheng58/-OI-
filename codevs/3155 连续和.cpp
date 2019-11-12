#include<iostream>
#include<cstdio>
using namespace std;
int f[1001],a[1001],tot=-11000000,sum;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)//Ë³Ðò 
	  {
	  	cin>>a[i];
	  	f[i]=max(f[i-1]+a[i],a[i]);
	  	if(f[i]>tot)
	  	{
	  		tot=f[i];
		  }
	  }
	  for(int i=1;i<=n;i++)
	    cout<<f[i]<<" ";
	cout<<tot;
	return 0;
}
