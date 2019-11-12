#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int element,s[10000001],a[10000001],b[10000001];
void put(int d)
{
	int now,next;
	s[++element]=d;
	now=element;
	while(now>1)
	{
		next=now>>1;
		if(s[now]<s[next])
		swap(s[now],s[next]);
		else return ;
		now=next;
	}
}
int get()
{
	int now,next,root;
	root=s[1];
	s[1]=s[element--];
	now=1;
	while(now*2<=element)
	{
		next=now*2;
		if(s[next]>s[next+1]) next++;
		if(s[now]>s[next]) 
		{
			swap(s[now],s[next]);
		}
		else return root;
		now=next;
	}
	return root;
}
int main()
{
	int x,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//put(x);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	{
		x=a[i]+b[j];
		put(x);
	}
	{
		
	}
	for(int i=1;i<=n;i++)
	{
		cout<<get()<<" ";
	}
	return 0;
}
