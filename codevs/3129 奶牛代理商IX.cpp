#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1000000
using namespace std;
int n,s[MAXN];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	  cout<<s[i]<<" ";
	return 0;  
}

