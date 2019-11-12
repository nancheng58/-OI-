#include<iostream>
#include<cstdio>
#define MAXN 11
using namespace std;
int g[MAXN][MAXN],flag,tot,x,y;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	 {
	 	cin>>g[i][j];
	 	if(g[i][j]==1) x=i,y=j;
	 }
	 while(g[x][y]!=n*n)
	 {
	 	if(tot==4) break;
		if(g[x][y]+1==g[x][y+1]) 
		{
			y=y+1;
			if(flag!=1)
			cout<<"R"<<" ",tot++;
			flag=1;continue;
		}
		if(g[x][y]+1==g[x+1][y])
		{
			x=x+1;
			if(flag!=2)
			cout<<"D"<<" ",tot++;
			flag=2;continue;
		}
		if(g[x][y]+1==g[x][y-1])
		{
			y=y-1;
			if(flag!=3)
			 cout<<"L"<<" ",tot++;
			 flag=3;continue;
		}
		if(g[x][y]+1==g[x-1][y])
		{
			x=x-1;
			if(flag!=4)
			  cout<<"F"<<" ",tot++;
			  flag=4;continue;
		}
	}
	return 0;
}
