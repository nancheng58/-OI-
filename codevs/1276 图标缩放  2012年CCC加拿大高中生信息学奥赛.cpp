#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=n;j++)
	  	  cout<<"*";
	  	for(int j=1;j<=n;j++)
		  cout<<"x";
		for(int j=1;j<=n;j++)
		  cout<<"*";
		cout<<endl;  
	  }
	for(int i=1;i<=n;i++)
	  {
		for(int j=1;j<=n;j++)
		  cout<<" ";
		for(int j=1;j<=2*n;j++)
		  cout<<"x";
		cout<<endl;    
	  }
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=n;j++)
	  	{
	  		cout<<"*";
		  }
		 for(int j=1;j<=n;j++)
	  	{
	  		cout<<" ";
		  } 
		 for(int j=1;j<=n;j++)
	  	{
	  		cout<<"*";
		  } 
		  cout<<endl;
		}  
	return 0;	
}
