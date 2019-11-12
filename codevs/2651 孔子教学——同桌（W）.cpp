#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 201
using namespace std;
int n,m,tot,w[11],v[11],f[11][MAXN][MAXN];
int main()
{
	char ch;
	int x;
	memset(f,-100,sizeof(f));
	cin>>n>>tot>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ch>>x;
		if(ch=='G') w[i]=3;
		else if(ch=='M') w[i]=2;
		else w[i]=-2;
		v[i]=x;
		f[i][0][0]=0;
	}
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=v[i];j--)
	    for(int k=0;k<=tot;k++)
	  {
	  	f[i][k][j]=max(f[i-1][k-1][j-v[i]]+w[i],f[i-1][k][j]);
	  }
	  int tot1=-1000000;
	  for(int i=1;i<=m;i++)
	    tot1=max(tot1,f[i][tot][m]);
	if(tot1!=-1000000) 
	  cout<<tot1;
	else cout<<-1;
	return 0;  
}
