#include<iostream>
#include<cstdio>
#define MAXN 101
using namespace std;
int g[MAXN][MAXN],n,s[MAXN],ans;
void slove(int u)
{
	if(u>n){
		ans++;return;
	}
	for(int i=1;i<=4;i++)
	{
		bool flag=false;
		for(int j=1;j<=n;j++)
		  if(g[u][j]&&s[j]==i) {
			flag=true;break;
		  }
		if(flag) continue;
		s[u]=i;
		slove(u+1);
		s[u]=0;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		scanf("%d",&g[i][j]);
	slove(1);
	printf("%d",ans);
	return 0;
}
