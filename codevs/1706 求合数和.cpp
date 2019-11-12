#include<iostream>
using namespace std;
int tot;
bool jd(int x)
{
	for(int i=2;i<x;i++)
	  if(x%i==0) return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(jd(i))
		  tot+=i;
	}
	cout<<tot;
	return 0;
}
