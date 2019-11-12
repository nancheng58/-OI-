#include<iostream>
#include<cstdio>
using namespace std;
int n;
int hs(int n)
{
	if(n>=0) return 5;
	else return hs(n+1)+hs(n+2)+1;
}
int main()
{
	cin>>n;
	cout<<hs(n);
	return 0;
}
