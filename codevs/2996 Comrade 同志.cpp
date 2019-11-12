#include<iostream>
using namespace std;
int tot;
int main()
{
	char ch;
	cin>>ch;
	if(ch>='a'&&ch<='z')
	{
		cout<<"I do not like lowercase letters!";
		return 0;
	}
	int n;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s==ch)
		  tot++;
	}
	cout<<tot;
	return 0;
}
