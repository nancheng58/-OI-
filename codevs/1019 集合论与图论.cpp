#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool g[1001][1001],flag;
int main()
{
	int t,n,e;
	cin>>t;
	while(t--)
	{
		memset(g,0,sizeof(g));
		flag=0;
		int x,y;
		cin>>n>>e;
		for(int i=1;i<=e;i++)
		{
			cin>>x>>y;
			g[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		  {
		  	if(g[i][j])
		  	{
		  		for(int k=1;k<=n;k++)
		  		  {
		  		  	if(g[j][k])
		  		  	  {
		  		  	  	if(!g[i][k])
		  		  	  	{
		  		  	  		flag=1;
		  		  	  		break;
							  }
						  }
					}
			  }
		  }
		if(flag)
		  cout<<"No"<<endl;
		else cout<<"Yes"<<endl;    
	}
}
