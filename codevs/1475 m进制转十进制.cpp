#include<iostream>
#include<cstdio>
using namespace std;

/*int jz()
{
	
	return sum;
}*/
int main()
{
	int n,m;
	cin>>n>>m;
	int i=0,sum=0,r,x=m;
	while(n>0)
	{
		
		r=n%10;
		n/=10;
		if(i==0)
		{
			sum+=r*1;
		}
		else 
		{
			sum+=r*m;
			m*=x;
		}
		i++;
	}
	cout<<sum;
	return 0;
}
