#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,x;
	cin>>n;
	cin>>k;
	int tot=k*6+5*n;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		if(x>k) tot+=(x-k)*6;
		else tot+=(k-x)*4;
		k=x;
	}
	cout<<tot;
	return 0;
}
