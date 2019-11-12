#include<iostream>
#include<cstdio>
using namespace std;
int a[1000];
int n,sum,max1,min1=0x7ffff;
int main()
{
	int k; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		sum+=k;
		if(k>max1)
		{
			max1=k;
		}
		if(k<min1)
		{
			min1=k;
		}
		a[k]++;
	}
	//cout<<sum;
	printf("\n");
	//cout<<max1;
	printf("\n");
	//cout<<min1;
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		  cout<<i<<endl;
	}
	return 0;
}
