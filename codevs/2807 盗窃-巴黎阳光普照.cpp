#include<iostream>
#include<cstdio>
using namespace std;
int tot;
struct d
{
	int o;
	int sum;
}
men[1001];
int main()
{
	int n,x,w,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>men[i].o;
		men[i].sum=men[i].o*i;
		
	}
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	  if(men[i].sum==men[j].sum)
		{
			x=(i+j)/2;
			break;
		}
	cout<<x<<" ";
	if(q==1)
	{
		for(int i=n;i>=x;i--)
		  tot+=men[i].o;
		cout<<tot;  
	}
	else
	{
		for(int i=1;i<=x;i++)
		  tot+=men[i].o;
		cout<<tot;  
	} 
	return 0;
}
