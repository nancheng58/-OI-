#include<iostream>
#include<cstdio>
using namespace std;
int tot;
int main() 
{
	int n;
	cin>>n;
	while(n!=1)
	{
		if(n%2==0)
		  {
		  	n/=2;
		  	tot++;
		  }
		else
		{
			n=n*3+1;
			tot++;
		}  
	}
	cout<<tot;
	return 0;
}
