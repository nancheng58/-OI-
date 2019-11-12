#include<iostream>
#include<cstdio>
using namespace std;
int n;
void qh(int m)
{
	int x;
	double i=1;
	double s=0;
	//for(i=1;i<=1000000;i++)
	while(s<=m)
	{
		s+=1.0/i;
		i++;
		//if(s>m) {x=i;break;}
	}cout<<i-1;
	
}
int main()
{
	//int n;
	cin>>n;
	qh(n);
	return 0;
}
