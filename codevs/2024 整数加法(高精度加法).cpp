#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 201
using namespace std;
int a[MAXN],b[MAXN],c[MAXN];
char m[MAXN],n[MAXN];
int main()
{
	scanf("%s %s",&m,&n);
	int l1=strlen(m);
	int l2=strlen(n);
	for(int i=0;i<=l1;i++)
	  if(l1-i-1>=0)
	  a[i]=m[l1-i-1]-48;
	for(int i=0;i<=l2;i++)
	  if(l2-i-1>=0)
	  b[i]=n[l2-i-1]-48;
	int l=max(l1,l2);
	for(int i=0;i<=l-1;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i-1]>=10)
		{
			c[i-1]%=10;
			c[i]++;
		}
		if(c[l-1]>=10)
		{
			c[l-1]%=10;
			c[l]=1;
		}
		  
	}
	while(!c[l]&&l>=1)
	  l--;
	for(int i=l;i>=0;i--)
	  cout<<c[i];
	return 0;    
}
