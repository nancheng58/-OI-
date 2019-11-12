#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 300
using namespace std;
char a[MAXN],s[MAXN][MAXN];
int l,r,n;
int main()
{
	for(int i=1;i<=26;i++) 
	  a[i]=i+96;
	cin>>l>>r>>n;
	for(int i=1;i<=n;i++) cin>>s[1][i];
	for(int i=2;i<=6;i++)  
	{
	    int x=-1;
		if(s[i-1][n]==a[r])
		{
			int z=1;
			while(s[i-1][n-z]==a[r-z]) z++;
			x=n-z;
		for(int k=1;k<x;k++)
		 s[i][k]=s[i-1][k];
		for(int k=x;k<=n;k++) 
		s[i][k]=a[s[i-1][x]-96+k-x+1];
		}
		else
		{
			for(int k=1;k<=n-1;k++) 
			s[i][k]=s[i-1][k];
			s[i][n]=a[s[i-1][n]-96+1];
		}
	  for(int k=1;k<=n;k++)
	  cout<<s[i][k];
	  printf("\n");
	}
	return 0;
}
