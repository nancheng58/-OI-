#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tot,x,sum,w;
char s[1000001],t[1000001];
int main()
{
	gets(t);
	gets(s);
	int l=strlen(t);
	int l2=strlen(s);
	for(int i=0;i<l2;i++)
	{
		if(s[i]>=97&&s[i]<=122) s[i]-=32;
		
	}
	for(int j=0;j<l;j++)
	{
		if(t[j]>=97&&t[j]<=122) t[j]-=32;
	}
	for(int i=0;i<=l2;i++)
	{
		sum=0;
		if((!s[i-1]||s[i-1]==32)&&s[i]==t[0]&&(!s[i+l]||s[i+l]==32))
		for(int j=i,k=0;k<l;j++,k++)
		{
			if(s[j]==t[k]) sum++; 
		}
		if(sum==l) 
		{
			tot++;
		if(tot==1) x=i;
		}
	}
	if(tot)
	cout<<tot<<" "<<x;
	else cout<<-1;
	return 0;
}
