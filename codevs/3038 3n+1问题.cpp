#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,a[1000000]={0},i;
void js(int y)
{
	if(y==1)  {return;}
	if(y%2==1) {y=3*y+1;a[i]++;js(y); return;}
	if(y%2==0) {y/=2;a[i]++;js(y); return;}
}
int sc()
{
	
}
int main()
{
	int x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		js(x);
	}
	for(i=1;i<=n;i++)
	  cout<<a[i]<<endl;
	//sc();
	return 0;
}
