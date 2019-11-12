#include<iostream>
#include<cstdio>
#define MAXN 1001
using namespace std;
int n,a[MAXN],b[MAXN];
bool flag;
long long tot;
bool jd(int i)
{
	tot=0;
	for(int j=i;j<=n;j++)
	{
		tot+=a[j];
		tot-=b[j];
		if(tot<0)
		{
			return 0;
		}
	}
	for(int j=1;j<i;j++)
	{
		tot+=a[j];
		tot-=b[j];
		if(tot<0)
		return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(jd(i))
		{
			flag=1;
			cout<<i<<" ";
		}	
	}
	if(!flag)
	  cout<<"No Result!";
	return 0;
}
