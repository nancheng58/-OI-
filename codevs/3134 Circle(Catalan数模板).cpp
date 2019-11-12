/*
  CatalanÊıÄ£°å. 
*/
#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n;
LL Catalan(LL x)
{
	if(x==1) return 1;
	return Catalan(x-1)*(4*x-2)/(x+1);
}
int main()
{
	cin>>n;
	printf("%lld ",Catalan(n));
	printf("%lld",n+1);
	return 0;
}
