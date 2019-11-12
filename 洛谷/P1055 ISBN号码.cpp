#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int tot,x;
int main()
{
	int k=1;
	char s[20];
	gets(s);
	int l=strlen(s);
	for(int i=0;i<l-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x=(s[i]-48)*k;
			tot+=x;
			k++;
		}
	}
	tot%=11;
	if(tot==10)
	{
		if(s[l-1]=='X') cout<<"Right";
	else
	{
		for(int i=0;i<l-1;i++)
	{
		cout<<s[i];
	}
	cout<<"X";
 	}
	}
	else
	{
		if(s[l-1]-48==tot) cout<<"Right";
	    else
	{
		for(int i=0;i<l-1;i++)
	{
		cout<<s[i];
 		}
	cout<<tot<<endl;
	
 	}
	}

	return 0;
}
