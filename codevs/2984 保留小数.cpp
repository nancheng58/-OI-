#include<iostream>
using namespace std;
string s;
bool b=0;
int main()
{
	cin>>s;
	int n,x;
	cin>>x;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]!='.')
		cout<<s[i];
		else
		{
			n=i;
			b=1;
		    break;
		 }
	}
	if(x!=0)
	cout<<'.';
	if(!b)
	{
		for(int i=1;i<=x;i++)
		  cout<<"0";
		  return 0;
	}
	else
	{
		int z=0;
		for(int i=n+1;i<n+x+1;i++)
		{
			cout<<s[i];
			z++;
		}
		while(z<x)
		{
			cout<<'0';
			z++;
		}
	if(s[n+x+1]>='5'&&s[n+x+1]!=85)
	  cout<<char(s[n+x]+1);
	else cout<<s[n+x];
	
	}
	
	return 0;
}
