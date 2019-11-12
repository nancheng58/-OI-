#include<iostream>
#include<cstdio>
using namespace std;
int max1,x;
int main()
{
	int n,q,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q>>w;
		int tot=q*w;
		cout<<tot<<endl;
		if(tot>=max1)
		{
			max1=tot;
			x=i;
		}
	}
	cout<<x;
	return 0;
	
}
