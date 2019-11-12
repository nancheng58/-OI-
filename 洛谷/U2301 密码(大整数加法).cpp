#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
int a[201],b[201],c[201];
char m[201],n[201];
int main()
{
	cin>>m;
	cin>>n;
	int l1=strlen(m);
	int l2=strlen(n);
	for(int i=l1-1;i>=0;i--)
	  a[i]=m[l1-1-i]-48;
	for(int i=l2-1;i>=0;i--)
	  b[i]=n[l2-1-i]-48;
	int l=max(l1,l2);
	for(int i=0;i<l;i++)
	  {
	  	c[i]=a[i]+b[i]+c[i];
	  	if(c[i]>=10)
	  	{
	  		c[i]%=10;
	  		c[i+1]++;
		}
		if(i==l-1&&c[i+1])
		{
			c[l]=1;
		}
	  }
	  
	while(l>=1&&c[l]==0)
	{
		l--;
	  }
	for(int i=l;i>=0;i--)
	  cout<<c[i];
	  return 0;  
}
