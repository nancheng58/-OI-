#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 110
using namespace std;
int n,father[MAXN],tot,k,sum;
struct data
{
	int v;
	int x;
	int y;
}
s[10001];
int cmp(const data &x,const data &y)
{
	return x.v<y.v;
}
int find(int x)
{
	if(x!=father[x]) father[x]=find(father[x]);
	return father[x];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  father[i]=i;
	int x;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	{
	  cin>>x;
	  if(x)
	  {
	  	s[++tot].x=i;
	  	s[tot].y=j;
	  	s[tot].v=x;
	  }
	}
	sort(s+1,s+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		int x=find(s[i].x);
		int y=find(s[i].y);
		if(x!=y)
		{
			father[x]=y;
			sum+=s[i].v;
			k++;
		}
		if(k==n-1) break;
	}
	cout<<sum;
	return 0;  
}
