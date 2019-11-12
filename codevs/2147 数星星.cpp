/*
离散化一发 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 500001
using namespace std;
int n;
bool b[MAXN];
struct data
{
	int o;
	int tot;
}
s[MAXN];
int cmp(const data &x,const data &y)
{
	if(x.tot!=y.tot)
	  return x.tot<y.tot;
	return x.o<y.o;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].tot;
		s[i].o=i;
	}
	sort(s+1,s+n+1,cmp);
	b[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(s[i].tot!=s[i-1].tot)//s[i]前面没有和它一样的说明它是第一个出现的 
		  b[s[i].o]=0;
		else b[s[i].o]=1;  
		
	}
	for(int i=1;i<=n;i++)
	  cout<<b[i];
	return 0;  
}
