/*
区间DP.
f[i][j]表示[i,j] 1号取得的最大值.
然后看一下这个区间取哪个端点.
但是我们不能只关心端点.
因为要有两个人轮流取数.
对于一个区间[i,j] 
如果一个人先手取了i,那么他后手取了[i+1,j]区间
一个人先手取了j,那么他后手取了[i,j-1]区间
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
