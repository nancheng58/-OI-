#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,s,q;
	cin>>a>>b>>c;
	q=(a+b+c)/2;
	if(a+b>c&&b+c>a&&a+c>b)
	{
		s=sqrt(q*(q-a)*(q-b)*(q-c));
		printf("%.2f",s);
		return 0;
	}
	cout<<"No answer";
	return 0;
	
}
