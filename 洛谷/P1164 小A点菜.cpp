#include<iostream>
#include<cstdio>
using namespace std;
int a[101],f[10100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  }
	  f[0]=1;
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=m;j>=a[i];j--)
	  {
	  	f[j]+=f[j-a[i]];cout<<f[j]<<" ";
	  	
	  }
	  cout<<endl;
	  }
	  cout<<f[m];
	 return 0; 
}
