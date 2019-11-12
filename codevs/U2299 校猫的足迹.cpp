#include<iostream>
using namespace std;
int main()
{
	int i,j,x,n;
	cin>>n;
	for(i=1;i<=n;i++)
	 {
	 	for(x=n-i;x>0;x--)
	 	  cout<<" ";
	 	for(j=1;j<=2*i-1;j++)
		  cout<<"+";
		cout<<endl;
	 }
	 return 0;

}

