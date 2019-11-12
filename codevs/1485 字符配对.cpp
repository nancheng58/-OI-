#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tot,num[27];
char s[1000001];
int main()
{
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		num[s[i]-97]++;
		
	}
	for(int i=0;i<=26;i++)
	{
		while(num[i]>=2&&num[i])
		{
			num[i]-=2;
		}
		tot+=num[i];
	}
	cout<<tot;
	return 0;
	
}
