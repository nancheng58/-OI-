#include<bits/stdc++.h>
#define MAXN 10001
using namespace std;
int n,m,s[MAXN],father[MAXN],tot,a[MAXN],ans;
int ffind(int x)
{
	return father[x]!=x?father[x]=ffind(father[x]):x;
	/*if(father[x]!=x) return father[x]=ffind(father[x]);
	return x;*/
}
void solve(int x,int y)
{
	int l1=ffind(x);
	int l2=ffind(y);
	if(l1!=l2)
	{
		father[l2]=l1;
		s[l1]+=s[l2];
	}
}
int main()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		s[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		solve(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(father[i]==i)  a[++tot]=s[i];
	}
	sort(a+1,a+tot+1,greater<int>());
	if(tot<=6) 
	{
		printf("^_^");
		return 0;
	}
	printf("T_T\n");
	for(int i=1;i<=6;i++)
	  ans+=a[i];
	cout<<ans;
	return 0;
}
