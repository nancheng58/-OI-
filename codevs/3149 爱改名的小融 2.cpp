#include<iostream>
using namespace std;
string s;
bool b=0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		b=0;
		int l=s.length();
		for(int j=0;j<l;j++)
		  {
		  	if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z');
		  	else
			  {
			  	cout<<"NO"<<endl;
			  	b=1;
			  	break;
			}
		  }
		  if(!b)
		  cout<<"YES"<<endl;
	}
	return 0;
}
