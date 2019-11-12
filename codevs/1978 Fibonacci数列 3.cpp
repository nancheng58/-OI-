#include<iostream>
#include<cstdio>
using namespace std;
//int n;
int fb(int n)
{
	if(n==1) return 1;
	if(n==2) return 1;
	else return fb(n-1)+fb(n-2);
}
int main()
{
	int m;
	cin>>m;
	cout<<fb(m);
	
}
