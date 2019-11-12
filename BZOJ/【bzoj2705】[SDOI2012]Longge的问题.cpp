#include<iostream>
#include<cmath>
#define LL long long
using namespace std;
LL n,m,ans;
LL phi(LL x)
{
	LL tot=x;
	for(LL i=2;i<=m;i++)
	  if(x%i==0)
	  {
		tot=tot/i*(i-1);
		while(x%i==0) x/=i;
	  }
	if(x>1) tot=tot/x*(x-1);
	return tot;
	
}
int main()
{
	cin>>n;
	m=sqrt(n);
	for(LL i=1;i<=m;i++)
	{
		if(n%i==0)
		{
			ans+=i*phi(n/i);
			if(i*i!=n) ans+=(n/i)*phi(i);
		}
	}
	cout<<ans;
	return 0;
}
