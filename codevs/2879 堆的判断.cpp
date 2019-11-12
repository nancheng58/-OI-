#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[101],n,i,j,x=0;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
	  	if(2*i>n) break;
	  	if(a[i]<a[2*i]||a[i]<a[2*i+1])
	  	{
	  		cout<<"NO";
	  		return 0;
		  }
	  }
	    
	    cout<<"YES";
		return 0;
}
