#include<iostream>
#include<cstdio>
using namespace std;
int a[1001],s[1001],w[1001],max1=1000000,x[101],r,tot,z;
bool b[1001],k,flag;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		w[100-a[i]]++;
		max1=min(max1,a[i]);
		a[i]=100-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(a[i]==s[j])
	  	{
	  		b[i]=1;
		  }
	  }
	  max1=100-max1;
	for(int i=1;i<=max1;i++)
	{
		if(w[i]>1)
		{
			z=1;
		  for(int j=1;j<=n;j++)
		  {
		  	if(a[j]==i)
		  	  {
		  	  	if(z==1)
		  	  	{
		  	  		z++;
				}
				else
				{
					x[j]=1;
		  	  	k=1;
		  	  	z++;
		  	  	r++;
				}
		  	  	
				}
		  }
		}
	  }
	  for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			k=1;
			x[i]=1;
			tot++;
		}
	}
	if(k&&tot)
	{
		cout<<r+tot<<endl;
	}
	else if(r)
	  cout<<r<<endl;
	if(k)
	{
		for(int i=1;i<=n;i++)
	    {
	    	if(x[i])
	    	  cout<<i<<" ";
		}
	  }  
	if(!k)
	  cout<<0;
	return 0;
}
