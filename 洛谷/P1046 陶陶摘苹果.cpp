#include<iostream>
using namespace std;
int tot;
int main()
{
	int a[100],x;
	for(int i=1;i<=10;i++)
	{
		cin>>a[i];
	}
	cin>>x;
	for(int i=1;i<=10;i++)
	{
		if(x+30>=a[i])
		tot++;
	}
	cout<<tot;
	return 0;
}
