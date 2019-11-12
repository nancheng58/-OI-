#include<iostream>
#include<cstdio>
#include<cstring>
long long sum1=1,sum2=1;
using namespace std;
int main()
{
	char s[100],t[100];
	gets(s);
	gets(t);
	int l1=strlen(s);
	int l2=strlen(t);
	for(int i=0;i<l1;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		sum1*=(s[i]-64);
	}
	for(int i=0;i<l2;i++)
	{
		if(t[i]>='A'&&t[i]<='Z')
		sum2*=(t[i]-64);
	}
	if((sum1%47)==(sum2%47)) cout<<"GO";
	else cout<<"STAY";
	return 0;

}
