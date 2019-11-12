#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int tot;
bool jd(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=2;i<n;i++)
	{
		if(jd(i))
		{
			printf("%d",i);
			printf("\n");
		}
		
	}
	return 0;
}
