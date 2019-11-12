#include<iostream>
#include<cstdio>
using namespace std;
int element,n,m;
long long s[10001000];
void put(int d)
{
	int next,now;
	s[++element]=d;
	now=element;
	while(now>1)
	{
		next=now>>1;
		if(s[now]<s[next])
		{
			swap(s[now],s[next]);
		}
		else return;
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
		if(now<element&&s[next]>s[next+1]) next++;
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
	int x,i,a,b,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		for(int j=1;j<=2*m;j++)
		{
			x=a*j*j+b*j+c;
			put(x);
		}
		
	}
	for(int j=1;j<=m;j++)
	{
		cout<<get()<<" ";
	}	
	return 0;
}
