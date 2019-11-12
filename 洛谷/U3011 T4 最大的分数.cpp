#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAXN 100001
using namespace std;
string s[MAXN];
bool cmp(const string &x,const string &y)
{
	return x>y;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	cout<<s[i];
}
