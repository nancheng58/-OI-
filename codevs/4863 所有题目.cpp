#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int n;
struct data
{
	int l,r;
	int tot;
}
s[MAXN];
int cmp(const data &x,const data &y)
{
	return x.l<y.l;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].l>>s[i].r;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			s[i].tot=1;
			for(int j=1;j<i;j++)
			{
				if(s[i].l>=s[j].r)
				  s[i].tot=max(s[i].tot,s[j].tot+1);
			}
			tot=max(tot,s[i].tot);
		}
		printf("%d\n",tot);
	}
	return 0;
}
