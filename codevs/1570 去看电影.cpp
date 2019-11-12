#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 5001
using namespace std;
int n,m,f[MAXN];
vector<int>v(1);
int main()
{
	int x;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=v[i];j--)
	  {
	  	f[j]=max(f[j],f[j-v[i]]+v[i]);
	  }
	cout<<f[m];
	return 0;  
}
