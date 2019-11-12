#include<iostream>
using namespace std;
int main()
{
	int i;
	long long a[10000];
	for(i=1;;i++)
	{
		cin>>a[i];
		if(a[i]==0) break;
	}
	for(int j=i-1;j>=1;j--)
	{
		cout<<a[j]<<" ";
	}
	return 0;
}
