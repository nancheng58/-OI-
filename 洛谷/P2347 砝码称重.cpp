#include<iostream>
#include<cstdio>
using namespace std;
int c[101],a[]={0,1,2,3,5,10,20},tot,sum;
int f[100001];
int main()
{
	int x;
	for(int i=1;i<=6;i++)
	  {
	  	cin>>x;
	  	c[i]=x;
		sum+=a[i]*c[i];
	  }
	  f[0]=1;
	for(int i=1;i<=6;i++)
	  for(int k=sum;k>=a[i];k--)
		for(int j=1;j<=c[i];j++)
	  {
	  	if(k-a[i]*j>=0)
	  	f[k]+=f[k-a[i]*j];
	}
	for(int i=1;i<=sum;i++)
	  if(f[i]) tot++;
	cout<<"Total="<<tot;
	return 0;
}
