#include<bits/stdc++.h>
using namespace std;
long long tot=1;
int main()
{
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		tot*=i;
		while(tot%10==0)
		{
			tot/=10;
			if((tot/1000000)%10!=0)break;
		}
	 tot%=1000000;
	}
	while(tot%10==0) tot/=10;
	cout<<tot%10;
	return 0;
}
