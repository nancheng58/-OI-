#include<iostream>
#include<cstdio>
using namespace std;
bool flag=0;
int main()
{
	int k;
	cin>>k;
	for(int i=10000;i<=30000;i++)
	{
		int x1=i/100;
		int x2=(i%10000)/10;
		int x3=i%1000;
		if((x1%k==0)&&(x2%k==0)&&(x3%k==0))
		{
			printf("%d\n",i);
			flag=1;
		}
	}
	if(!flag)
	cout<<"no";
	return 0;
}
