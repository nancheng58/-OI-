#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int tot,ans,g[MAXN][MAXN];
bool b[MAXN][MAXN];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	cin>>g[i][j];
	  	if(g[i][j])
	  	b[i][j]=1;
	  }
	int x,y;
	for(int i=1;i<=5;i++)
	{
		cin>>x>>y;
		g[x][y]-=2;
		if(g[x][y]<=0&&b[x][y]) ans++,b[x][y]=0;
		g[x-1][y]-=1;
		if(g[x-1][y]<=0&&b[x-1][y]) ans++,b[x-1][y]=0;
		g[x+1][y]-=1;
		if(g[x+1][y]<=0&&b[x+1][y]) ans++,b[x+1][y]=0;
		g[x][y-1]-=1;
		if(g[x][y-1]<=0&&b[x][y-1]) ans++,b[x][y-1]=0;
		g[x][y+1]-=1;
		if(g[x][y+1]<=0&&b[x][y+1]) ans++,b[x][y+1]=0;
		g[x-1][y-1]-=1;
		if(g[x-1][y-1]<=0&&b[x-1][y-1]) ans++,b[x-1][y-1]=0;
		g[x-1][y+1]-=1;
		if(g[x-1][y+1]<=0&&b[x-1][y+1]) ans++,b[x-1][y+1]=0;
		g[x+1][y-1]-=1;
		if(g[x+1][y-1]<=0&&b[x+1][y-1]) ans++,b[x+1][y-1]=0;
		g[x+1][y+1]-=1;
		if(g[x+1][y+1]<=0&&b[x+1][y+1]) ans++,b[x+1][y+1]=0;
	}
	cout<<ans;
	return 0;
}
