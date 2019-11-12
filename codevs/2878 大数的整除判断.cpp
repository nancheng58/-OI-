#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int l1=s1.length();
	int l2=s2.length();
	
	int x=char(s1[l1-1]-48)*char(s2[l2-1]-48);
	if(x%5==0) 
	  cout<<"Yes";
	else   
	cout<<"No";
	return 0;
}
