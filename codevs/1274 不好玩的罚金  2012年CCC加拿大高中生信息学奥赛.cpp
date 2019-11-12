#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	cout<<"Enter the speed limit: ";
	cin>>n;
	cout<<"Enter the recorded speed of the car: ";
	cin>>k;
	int l=k-n;
	if(l<=0)
	{
		cout<<"Congratulations, you are within the speed limit";
	}
	if(l>30)
	{
		cout<<"You are speeding and your fine is $ 500";
	}
	if(l>=1&&l<=20)
	{
		cout<<"You are speeding and your fine is $ 100";
	}
	if(l>20&&l<=30)
	{
		cout<<"You are speeding and your fine is $ 270";
	}
	return 0;
}
