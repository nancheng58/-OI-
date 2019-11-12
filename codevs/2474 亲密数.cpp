#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x,y,tot=100001,a[1001];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)
		 {
		 	if(abs(a[i]*1.0-a[i-1]*1.0)<tot)
		 	{
		 		tot=abs(a[i]*1.0-a[i-1]*1.0);
		 		x=a[i-1];
		 		y=a[i];
			 }
		 }
	}
	cout<<x<<" "<<y;
	return 0;
}
