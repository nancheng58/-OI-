#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[11];

int main()
{	
	int n;
	int f[1001];
	memset(f,10,sizeof(f));
	for(int i=1;i<=10;i++)
	  cin>>a[i];
	cin>>n;
	f[0]=0;
	for(int i=1;i<=10;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(j>=i)
	  	f[j]=min(f[j-i]+a[i],f[j]);
		}
	cout<<f[n];
	return 0;	
}
