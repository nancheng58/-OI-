#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
	{
		cout<<"yes";
		return 0;
	}
	cout<<"no";
	return 0;
}
