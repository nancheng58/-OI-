#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,max1,min1=100000001;
float tot;
int main()
{
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>x;
	  	max1=max(x,max1);
	  	min1=min(x,min1);
	  	tot+=x;
	  }
	int s=round((tot+0.5)/n);
	//tot=tot/n+0.5;
	cout<<max1<<endl<<min1<<endl<<s;
	return 0;  
}
