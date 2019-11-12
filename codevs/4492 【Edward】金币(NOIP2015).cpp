#include<iostream>
#include<cstdio>
using namespace std;
int tot,t,m;
int main()
{
	int n,i=1;
	cin>>n;
	while(t<n)
	{
		tot+=i*i;
		t+=i;
		i+=1;
		m-=i;
	}
	if(t>n)
	tot-=(i-1)*(t-n);
	cout<<tot;
	return 0;
}
