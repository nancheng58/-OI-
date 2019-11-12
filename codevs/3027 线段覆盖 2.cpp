#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int tot;
struct data
{
	int w;
	int r;
	int l;
	int tot;
}
s[1001];
int cmp(const data &x,const data &y)
{
	return x.l<y.l;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i].l>>s[i].r>>s[i].w;
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i].tot=s[i].w;
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i-1;j++)
	  {
	  	if(s[i].l>=s[j].r)
	  	  s[i].tot=max(s[i].tot,s[j].tot+s[i].w);
	  }
	for(int i=1;i<=n;i++)
	  tot=max(tot,s[i].tot);
	cout<<tot;
	return 0;    
}

