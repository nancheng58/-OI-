#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,m,sum=0;
	long int n;
	scanf("%d%ld",&m,&n);
	int k=m;
	for(i=1;i<=n;i++)
	{
		if(k==8) k=1;
		if(k!=6&&k!=7)
		{
			sum+=250;
		}
		k++;
		  
	}
	printf("%d",sum);
	return 0;
}
