#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int tot;
bool jd(int s)
{
	for(int i=2;i<=sqrt(s);i++)
	{
		if(s%i==0) return 0;
	}
	return 1;
}
int main()
{
	int r,l;
	cin>>l>>r;
	if(r<l) 
	{
		swap(r,l);
	}
	for(int i=l+1;i<r;i++)
	{
		if(jd(i)==1) tot+=i;
	}
	cout<<tot;
	return 0;
}
