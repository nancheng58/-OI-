/*
����DP.
f[i][j]��ʾ[i,j] 1��ȡ�õ����ֵ.
Ȼ��һ���������ȡ�ĸ��˵�.
�������ǲ���ֻ���Ķ˵�.
��ΪҪ������������ȡ��.
����һ������[i,j] 
���һ��������ȡ��i,��ô������ȡ��[i+1,j]����
һ��������ȡ��j,��ô������ȡ��[i,j-1]����
*/
#include<iostream>
#include<cstdio>
#define MAXN 101
using namespace std;
int n,f[MAXN][MAXN],sum[MAXN];
void slove()
{
    for(int i=n;i>=1;i--)
      for(int j=i+1;j<=n;j++) 
        f[i][j]=max(sum[j]-sum[i-1]-f[i+1][j],sum[j]-sum[i-1]-f[i][j-1]);
}
int main()
{
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        f[i][i]=x;
        sum[i]=sum[i-1]+x;
    }
    slove();
    printf("%d %d",f[1][n],sum[n]-f[1][n]);
    return 0;
}
