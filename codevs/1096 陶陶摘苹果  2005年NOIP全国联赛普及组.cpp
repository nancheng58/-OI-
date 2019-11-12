#include<iostream>
using namespace std;
int a[11],tot;
int main()
{
	int n;
	for(int i=1;i<=10;i++)
	  cin>>a[i];
	cin>>n;
	n+=30;
	for(int i=1;i<=10;i++)
	  if(a[i]<=n)
	    tot++;
	cout<<tot;
	return 0;	  
}
