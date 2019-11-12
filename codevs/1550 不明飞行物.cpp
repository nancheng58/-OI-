#include<iostream>
using namespace std;
int main()
{
	string s1,s2;
	int a1=1,a2=1,len1,len2;
	cin>>s1>>s2;
	len1=s1.length();
	len2=s2.length();
	for(int i=0;i<len1;i++)
	{
	a1*=s1[i]-64;
	 a1%=47;
	}
	for(int i=0;i<len2;i++)
	{
		a2*=s2[i]-64;
		  a2%=47;
	}
	
	
	if(a1==a2)
	{
	cout<<"GO"<<endl;
	cout<<"r1=r2="<<a2;	
	}
	else
	{
		cout<<"STAY"<<endl;
		cout<<"r1="<<a1<<" "<<"r2="<<a2;
	}
	return 0;
}
