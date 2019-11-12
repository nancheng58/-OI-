#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	for(i=2;n%i;i++);
	cout<<n/i;//i为另一质数（最小） 
	return 0;
}
