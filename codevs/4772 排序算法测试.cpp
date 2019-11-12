#include<iostream>
#include<algorithm>
#define r for(int i=1;i<=n;i++)
using namespace std;
int a[100001];
int main()
{
	int n;
	cin>>n;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	r
	cin>>a[i];
	sort(a+1,a+n+1);
	r
	cout<<a[i]<<" ";
	return 0;
}
