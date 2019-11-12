#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1001][1001];
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	memset(f,10,sizeof(f));
	for(int i=1;i<=l;i++)
	  f[i][i]=1;
	for(int i=1;i<=1;i++)
	  for(int j=l-i+1;j<=l;j++)
	    for(int k=i;k<j;k++)
	    {
	    	if(((s[i-1]=='('&&s[j-1]==')')||(s[i-1]=='['&&s[j-1]==']'))&&(i!=j-1))
	    	  f[i][j]=f[i+1][j-1];
	    	f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);  
		}
		cout<<f[1][l];
		return 0;
}
