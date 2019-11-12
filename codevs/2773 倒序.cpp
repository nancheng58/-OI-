#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
string s;
char a[1001];
int k,x;
int main()
{
	char ch;
	int i=1;
	while(scanf("%c",&ch)==' ')
	{
		
		a[i++]=ch;
	}
	int l=s.length();
	/*for(int i=1;i<=l;i++)
	{
		if(a[i]!=' ')
		  s[k][++x]=a[i];
		else 
		{
		k++;
		x=0;	
		}
	}*/
	for(int j=i;j>=1;j--)
	  cout<<a[j];
	return 0; 
}
