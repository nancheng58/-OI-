#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	double tot=0;
	cin>>n;
	for(int i=1;;i++)
	{
		tot+=1.0/i;
		if(tot>=n)
		{
			cout<<i;
			return 0;
		}
		if(i>=5000000)
		{
			cout<<"Error!";
			return 0;
		}
	}

}
