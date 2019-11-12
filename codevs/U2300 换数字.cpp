#include<iostream>
#include<cstdio>
using namespace std;
char a[1001],m;
int head;
int main()
{
	gets(a);
	cin>>m;
	for(int i=0;a[i];i++)
	  if(a[i]=='2')
	  {
	  	a[i]=m;
	  }
	  for(int i=0;a[i];i++)
	  {
	  	if(a[i]=='0')
	    {
	    	head++;
		}
		else break;
	  }
	    
	for(int i=head;a[i];i++)
	  cout<<a[i];
	return 0;
}
