#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
int a[MAXN],n,m,len;
bool jd(int x)
{
	int sum=1,k=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[k]>=x) sum++,k=i;
	}
	if(sum>=m) return 1;
	else return 0;
}
int erfen(int l,int r)
{
	int mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(jd(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],len=max(len,a[i]);
	sort(a+1,a+n+1);
	cout<<erfen(0,len);
	return 0;
}
