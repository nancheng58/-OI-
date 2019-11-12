#include<iostream>
#include<cstdio>
#define MAXN 1001
#include<algorithm>
#include<vector>
using namespace std;
bool g[MAXN][MAXN];
int n,e;
vector<int>a(1);
vector<int>b(1);
void floyed()
{
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(g[i][k]&&g[k][j])
	    	  g[i][j]=true;
		}
}
int main()
{
	cin>>n>>e;
	int x,y;
	for(int i=1;i<=e;i++)
	{
		cin>>x>>y;
		//a.push_back(x);
		//b.push_back(y);
		g[x][y]=1;
	}
	floyed();
	for(int i=1;i<=n;i++)
	{
		if(g[i][i])
		  printf("T\n");
		else printf("F\n");  
	}
	return 0;
}
