#include<iostream>
using namespace std;
int tot;
int main()
{
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if((s[0]>='A'&&s[0]<='G')||(s[0]>='R'&&s[0]<='T'))
		  tot++;
	}
	cout<<n-tot;
	return 0;
}
