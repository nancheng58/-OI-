/*
������DP.
f[i][j]��ʾǰi�����ֳ�j�������ֵ.
��i-1��ʼɨ.
ɨһ��ǰk�������ֵ��Ϊ����ֵ.
Ȼ��f[i][j]=min(f[i][j],f[k][j-1]+max);
ת�Ƶ�ʱ����j-1��+max.
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
