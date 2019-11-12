#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string a;
int i,j,n,m,k,l;
int main()
{
	i=1;
	cin>>a;
	n=a.length();
	for(i=0;i<n;++i)
	{
		if(a[i]=='.')
		 { l=i;break;
		   } 
	}
	for(i=l+1;i<n;++i)
	{
		if(a[i]!=48)
		{
			k=1;
			break;
		}
		k=0;
	}
	if(k==1)
	{
		cout<<"No";
	}
	else cout<<"Yes";
}

