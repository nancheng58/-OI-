/*
分块.
把数据分为√n块.
答案无非有两种:
1是查询区间中某一块的区间众数.
2是剩余的不足一块的数.
然后一开始是没想明白的(由于本人比较弱
但是考虑一下确实是这样的.
一开始认为答案可能不是某个区间的众数.
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#define MAXN 50001
using namespace std;
int n,m=200,q,lastans,belong[MAXN],a[MAXN],tot,id[MAXN],f[510][510],cnt[MAXN];
vector<int>g[MAXN];
map<int,int>ma;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove(int x)
{
	memset(cnt,0,sizeof cnt);
	int max1=0,ans=0;
	for(int i=(x-1)*m+1;i<=n;i++)
	{
		cnt[a[i]]++;
		if(cnt[a[i]]>max1||(cnt[a[i]]==max1&&id[a[i]]<id[ans]))
		  max1=cnt[a[i]],ans=a[i];
		f[x][belong[i]]=ans;
	}
	return ;
}
int query(int x,int y,int k)
{
	return upper_bound(g[k].begin(),g[k].end(),y)-lower_bound(g[k].begin(),g[k].end(),x);
}
int slovequery(int x,int y)
{
	int ans=f[belong[x]+1][belong[y]-1];
	int max1=query(x,y,ans);
	for(int i=x;i<=min(y,belong[x]*m);i++)
	{
		int t=query(x,y,a[i]);
		if(t>max1||(t==max1&&id[a[i]]<id[ans]))
		  max1=t,ans=a[i];
	}
	if(belong[x]!=belong[y])
	{
		for(int i=(belong[y]-1)*m+1;i<=y;i++)
		{
			int t=query(x,y,a[i]);
			if(t>max1||(t==max1&&id[a[i]]<id[ans]))
		  	  max1=t,ans=a[i];
		}
	}
	return ans;
}
int main()
{
	int x,y;
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(!ma[a[i]]) ma[a[i]]=++tot,id[tot]=a[i];
		a[i]=ma[a[i]];
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) belong[i]=(i-1)/m+1;
	for(int i=1;i<=belong[n];i++) slove(i);
	while(q--)
	{
		x=read(),y=read();
		x=(x+lastans-1)%n+1,y=(y+lastans-1)%n+1;
		if(x>y) swap(x,y);
		lastans=id[slovequery(x,y)];
		printf("%d\n",lastans);
	}
	return 0;
}
