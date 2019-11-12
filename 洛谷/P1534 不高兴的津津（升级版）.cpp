#include<iostream>
using namespace std;
int tot;
int main()
{
	int i,x,y,n,k=0;
	cin>>n;
	for(i=1;i<=n;i++)	
	{
		cin>>x>>y;
		int q=x+y;
		k=q-8+k;
		tot+=k;
	}
	cout<<tot;
	return 0;
}
