/*
二分答案+sort.
思路:sort有序后二分
找一个对ans有贡献的数x（即<=k/2）
二分k-x的下界 那么之前的数与该数组合均可以构成一组合
*/
#include<bits/stdc++.h>
#define MAXN 10001
#define LL long long
using namespace std;
LL a[MAXN],tot,m,n;
LL erfen(LL x)
{
	LL l=0,r=n+1,mid;
	while(r-l>1)
	{
		mid=(r+l)/2;
		if(x==a[mid]) return x;
		else if(x<a[mid])r=mid-1;
		else l=mid+1;
	}
	return mid;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	cin>>m;
	while(m--)
	{
		tot=0;
		LL k;
		cin>>k;
		for(int i=1;a[i]<=k/2;i++)
		{
			LL x=erfen(k-a[i]);
			if(x>i)
			{
				tot+=(x-i);
			}
		}
		printf("%lld\n",tot);
	}
	return 0;
}
