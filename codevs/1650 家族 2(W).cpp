/*
Ê§°ÜµÄ¶ÁÈë
*/#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAXN 101
using namespace std;
bool  g[MAXN][MAXN];
string s[101];
int a[101];
int n,m,tot;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
void bfs(int x,int y)
{
	g[x][y]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		if(g[xx][yy])
		{
			bfs(xx,yy);
		}
	}
}
int main()
{	
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		a[i]=s[i].length();
	}
	for(int i=1;i<=n;i++)
	  for(int j=0;j<a[i];j++)
	{
		if(s[i][j]>='A'&&s[i][j]<='Z'||s[i][j]>='a'&&s[i][j]<='z') g[i][j]=1;
		else //if(isalpha(s[i][j]))
		  g[i][j]=0;
	}for(int i=1;i<=n;i++)
	   {for(int j=0;j<a[i];j++)
	 cout<<g[i][j];
	  	cout<<endl;
	  }
	    
	for(int i=1;i<=n;i++)
	  for(int j=0;j<a[i];j++)
	  {
	  	if(g[i][j])
	  	{
	  		bfs(i,j);
	  		tot++;
		  }
	  }
	  cout<<tot;
	return 0;
}
