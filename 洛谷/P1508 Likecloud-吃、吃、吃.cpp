/*
����DP.
��Ϊ�������Ž���˵
����ѡ�Ͳ�ѡ�Ǿ��Ե�.
�������ǿ��Դ��յ㿪ʼ��.
���ӿ��ܵ������ȡmax. 
*/
#include<iostream>
#include<cstdio>
#define MAXN 201
using namespace std;
int f[MAXN][MAXN],g[MAXN][MAXN],n,m,x,y;
int main()
{
	scanf("%d %d",&n,&m);
	x=n,y=(m+1)/2;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&g[i][j]);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    f[i][j]=max(f[i-1][j],max(f[i-1][j-1],f[i-1][j+1]))+g[i][j];
	printf("%d",max(f[x][y],max(f[x][y-1],f[x][y+1])));
	return 0; 
}
