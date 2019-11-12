#include<iostream>
#include<cstdio>
#define MAXN 10001
#define xo 11
#define mod 10003
using namespace std;
int f[MAXN];
string s;
int haxi(string s)
{
	long long tot=0;
	for(int i=0;i<s.length();i++)
	{
		tot+=(s[i]-96)*xo;
	}
	return tot%mod;
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>s;
	  	f[haxi(s)]=1;
	  }
	cin>>m;  
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		if(f[haxi(s)])
		  cout<<"Yes"<<endl;
		else cout<<"No"<<endl;  
	}  
	return 0;
}
