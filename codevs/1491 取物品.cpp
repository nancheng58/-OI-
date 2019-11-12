#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 1001
using namespace std;
//vector<int>f;
int s[MAXN],f[MAXN];
int n,m,tot;
int main()
{
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++)
	{
	  cin>>x;
	  s[x]++;
	  tot=max(tot,x);
	}
	f[0]=1;
	for(int i=1;i<=tot;i++)
	{
		if(s[i])
		for(int j=m;j>=1;j--)
		  for(int k=1;k<=s[i];k++)
		  if(j-k>=0)
		    f[j]+=f[j-k];
	}
	//for(int i=1;i<=tot;i++)
	  //cout<<f.at(i)<<" "; 
	cout<<f[m];  
	return 0; 
}
