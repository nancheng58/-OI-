#include<bits/stdc++.h>
#define MAXN 2001
using namespace std;
struct data
{
	int o;
	int x;
}
s[MAXN];
int n,m;
int cmp(const data &x,const data &y)
{
	if(x.x!=y.x)
	return x.x>y.x;
	return x.o<y.o;
}
int main()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i].x;
		s[i].o=i;
	 } 
	 //sort(s+1,s+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(s[x].x>s[y].x) printf("%d win!\n",x);
		else if(s[x].x<s[y].x) printf("%d win!\n",y);
		else 
		{
			int z=s[x].o<s[y].o?s[x].o:s[y].o;
			printf("%d win!\n",x);
		}
	}
}
