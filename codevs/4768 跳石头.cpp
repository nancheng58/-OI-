/*
���ִ�+����. 
��Ȼans�ض���[0,len]��,
sort�����ans �ټ�����н�.
��ע�⴦����ǰ�߿���ʯͷ�Ƚϣ�
�൱��������ʯͷ.
*/
#include<bits/stdc++.h>
#define MAXN 50001
using namespace std;
int a[MAXN],n,m,len;
bool jd(int x)
{
	int sum=0,k=0;
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]-a[k]<x) sum++;
		else k=i;//��here.
}
	if(sum>m) return 0;
	else return 1;
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
	cin>>len>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=0,a[n+1]=len;
	cout<<erfen(0,len);
	return 0;
}
