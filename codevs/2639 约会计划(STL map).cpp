#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define MAXN 2010
using namespace std;
map<string,int>G;
int father[MAXN];
int n,m,k;
int find(int x)
{
	if(x!=father[x]) father[x]=find(father[x]);
	return father[x];
}
int main()
{
	string s,ss;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		G[s]=i;
		father[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s>>ss;
		int a=find(G[s]);
		int b=find(G[ss]);
		if(a!=b)
		{
			father[a]=b;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s>>ss;
		if(find(G[s])==find(G[ss]))
		  {
		  	cout<<"safe";
		  	printf("\n");
		  }
		else
		{
			cout<<"cc cry";
			printf("\n");
		  }  
	}
	return 0;
}
