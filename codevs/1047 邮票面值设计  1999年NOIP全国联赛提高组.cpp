#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
int dp[1000001],a[40],tot[40];
int n,k,max1;
void yz()//求解最优解  
{
	int i=0;
	dp[0]=0;
	while(dp[i]<=n)
	{
		i++;
		dp[i]=MAXN;
		for(int j=0;j<k&&i>=a[j];j++)
		  dp[i]=min(dp[i],dp[i-a[j]]+1);
		if(i-1>max1)
		{
			max1=i-1;
			for(int j=0;j<k;j++)
			  tot[j]=a[j];
		  }  
	}
}
void dfs(int t)//DFS+剪枝 （枚举方案） 
{
	if(t==k)
	{
		yz();
		return ;
	}
	for(int i=a[t-1]+1;i<=a[t-1]*n+1;i++)
	{
		a[t]=i;
		dfs(t+1);
	}
}
int main()
{
	a[0]=1;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		max1=0;
		dfs(0);
		for(int i=0;i<k;i++)
		  {
		  	cout<<tot[i]<<" ";
		  }
		printf("\n");  
		cout<<"MAX="<<max1;
		printf("\n");  
	}
	return 0;
}

