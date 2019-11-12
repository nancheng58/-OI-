#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct data{
	int lc;
	int rc;
    }t[100];
int first(int p=1)
{
	if(p)
	{
		cout<<p<<" ";
		if(t[p].lc) first(t[p].lc);
		if(t[p].rc) first(t[p].rc);
	}
	
}
int mid(int p=1)
{
	if(p)
	{
		if(t[p].lc) mid(t[p].lc);
		cout<<p<<" ";
		if(t[p].rc) mid(t[p].rc);
	}
}
int last(int p=1)
{
	if(p)
	{
		if(t[p].lc) last(t[p].lc);
		if(t[p].rc) last(t[p].rc);
		cout<<p<<" ";
	}
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>t[i].lc>>t[i].rc;
	first();
	cout<<endl;
	mid();
	cout<<endl;
	last();
	return 0;
}
