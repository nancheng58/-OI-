#include<iostream>
using namespace std;
int main()
{
	double n,k=2,sum=2;
	long long i;
	cin>>n;
	for(i=2;;i++)
	{
		k=0.98*k;
		sum+=k;
		if(sum>=n) {break; 
		}
	}
	cout<<i;
	return 0;
}
