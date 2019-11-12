#include<bits/stdc++.h>
#define MAXN 21 
using namespace std;
int tot;
map<char,int>g;
char s[MAXN];
int main()
{
	g['I']=1,
	g['V']=5,
	g['X']=10,
	g['L']=50,
	g['C']=100,
	g['D']=500,
	g['M']=1000;
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(i%2==1)
		{
			if(g[s[i]]<g[s[i+2]])
			 tot-=(s[i-1]-48)*g[s[i]];
			else tot+=(s[i-1]-48)*g[s[i]];
		 } 
	}
	cout<<tot;
	return 0;
}
