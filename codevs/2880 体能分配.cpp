#include<iostream>
#include<cmath>
using namespace std;
double a[1001],tot,sum,max1=1000000;
int main()
{
	int n,k=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
		max1=min(max1,a[i]);
	}
	tot-=a[n];
	tot/=(n-1);
	for(int i=1;i<=n-1;i++)
	{
		sum=abs(a[i]-tot);
		if(sum>tot/10)
		{
			k=0;
			break;
		}
	}
	if(a[n]==max1)
	{
		k++;
	}
	if(k==2)
	  cout<<"Good";
	else if(k==1)
	  cout<<"Pass";
	else
	  cout<<"Bad";
	return 0;   
}
