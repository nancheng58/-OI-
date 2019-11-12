#include<iostream>
using namespace std;
long long tot,al=1;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		al*=i;
		if(al%10==0)
		{
			//al/=10;
			tot++;
			al/=10;
		}
		
	}
	cout<<tot<<" "<<al;
	return 0;
}
