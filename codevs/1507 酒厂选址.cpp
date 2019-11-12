#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 10001
using namespace std;
long long g[MAXN],s[MAXN],tot=0x7fffffffffffffff,n,z,t;
void floyed()
{
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	//if(i!=j&&j!=k&&i!=k)
	    	  //g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	    }
}
int main()
{
	int x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>x;
		g[i+1]=g[i]+x;
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=1;j<=n;j++)
		{
			z=abs(g[j]-g[i]);
			t+=s[j]*min(z,g[n+1]-z);
		}
		tot=min(tot,t);
	}
	//floyed();
	cout<<tot;
	return 0;
} 
