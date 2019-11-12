#include<iostream>
#include<cstdio>
using namespace std;
struct data
{
	int a;
	int b;
	char ch;
	char ch2;
}
aa;
int main()
{
	cin>>aa.a>>aa.ch>>aa.b>>aa.ch2;
	cout<<aa.a<<"+"<<aa.b<<"="<<aa.a+aa.b;
	return 0;
}
