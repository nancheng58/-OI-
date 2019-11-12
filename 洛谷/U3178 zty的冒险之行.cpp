/*
划分型DP.
f[i][j]表示前i个数分成j组的最优值.
从i-1开始扫.
扫一个前k个的最大值作为代表值.
然后f[i][j]=min(f[i][j],f[k][j-1]+max);
转移的时候考虑j-1组+max.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1001
using namespace std;
int s[MAXN],f[MAXN][MAXN],n,m,tot;
int main()
{
	memset(f,127/3,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&s[i]),f[i][0]=0;;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=m;j++)
	    {
	    	tot=s[i];
	    	for(int k=i-1;k>=0;k--)
	    	{
	    		f[i][j]=min(f[i][j],f[k][j-1]+tot);
				tot=max(tot,s[k]);
			}
		}
	}
	printf("%d",f[n][m]);
}
