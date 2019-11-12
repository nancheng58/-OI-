#include<iostream>
#include<cstdio>
using namespace std;
long  long a,b,p,tot,ans=1;
int main()
{
	cin>>a>>b>>p;
	tot=a%p;
	for(int i=1;i<=b;i++)
	  ans=(ans*tot)%p;
	cout<<ans;
	return 0;  
}
