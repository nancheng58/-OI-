#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	for(i=2;n%i;i++);
	cout<<n/i;//iΪ��һ��������С�� 
	return 0;
}
