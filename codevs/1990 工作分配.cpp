#include<iostream>
#include<cstdio>
using namespace std;
long long a[4][4],tot;
int main()
{
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	  {
	  	cin>>a[i][j];
	  }
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	    for(int k=1;k<=3;k++)
	    if(i!=j&&i!=k&&k!=j)
	    {
	    	tot=max(tot,a[1][i]+a[2][j]+a[3][k]);
		}
	cout<<tot;
	return 0;
}
