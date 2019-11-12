#include<bits/stdc++.h>
#define INF 0x9fffffff
using namespace std;
long long tot,min1,x;
int n,m;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		min1=INF;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%ld",&x);
			min1=min(x,min1);
		}
		tot+=min1;
	}
	cout<<tot;
	return 0;
}
